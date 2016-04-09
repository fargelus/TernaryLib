/*
 * библиотека для работы с троичной логикой
 * дальше подробное описание всех классов
 */

#ifndef TERNARY_LOGIC
#define TERNARY_LOGIC

#include <cstring>
#include <cmath>

struct out_of_range
{
    const char* description;
    out_of_range() {strcpy(description, "Ошибка выход за пределы диапазона");}
};

class Trit
{
    private:
        enum state {NEG, UNKNOWN, POS};
        long pos;
        static int base;

    public:
        Trit() : pos(-1), state(UNKNOWN) {}
        Trit(long new_pos)
        {
            if (new_pos < 0)
                throw out_of_range();

            pos = new_pos;
            switch (new_pos % 3)
            {
                case 0:
                    state = NEG;
                    break;
                case 1:
                    state = UNKNOWN;
                    break;
                case 2:
                    state = POS;
                    break;
               default:
                    break;
            }
        }

        unsigned get_number()
        {
            return static_cast<unsigned> (state) * pow(base, pos);
        }
};

int Trit::base = 3;

#endif // TERNARY_LOGIC

