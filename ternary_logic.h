/*
 * библиотека для работы с троичной логикой
 * дальше подробное описание всех классов
 */

#ifndef TERNARY_LOGIC
#define TERNARY_LOGIC

#include <cstring>
#include <cmath>
#include <QVector>
#include <iostream>

struct out_of_range
{
    char* description;
    out_of_range() {strcpy(description, "Ошибка выход за пределы диапазона");}
};

enum state {NEG, UNKNOWN, POS};

class Trit
{
    private:
        state st;
        long pos;
        static int base;

    public:
        Trit() : pos(-1), st(UNKNOWN) {}

        Trit(state new_state, long new_pos)
        {
            if (new_pos < 0)
                throw out_of_range();
            pos = new_pos;
            st = new_state;
        }

        Trit(long new_pos)
        {
            if (new_pos < 0)
                throw out_of_range();

            pos = new_pos;
            switch (new_pos % base)
            {
                case 0:
                    st = NEG;
                    break;
                case 1:
                    st = UNKNOWN;
                    break;
                case 2:
                    st = POS;
                    break;
               default:
                    break;
            }
        }

        unsigned get_number()
        {
            return static_cast<unsigned>(st) * pow(base, pos);
        }

        state getState() { return st; }
};

int Trit::base = 3;


class Tryte
{
    private:
        QVector<Trit> sequence;
        const int size = 6;

    public:
        Tryte()
        {
            for (int i = 0; i < size; ++i)
                sequence.push_back(Trit(NEG, i));
        }

        void display()
        {
            for (Trit& tr: sequence)
                std::cout << tr.getState();
            std::cout << std::endl;
        }

        Tryte(unsigned long number);    // перевод числа в троичку
};


#endif // TERNARY_LOGIC

