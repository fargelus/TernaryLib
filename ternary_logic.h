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
        short pos;
        static int base;
        bool overflow;

    public:
        Trit() : st(UNKNOWN), pos(0), overflow(false) {}

        Trit(state, short);

        Trit(short);

        unsigned get_number();

        state getState();

        Trit& operator+ (Trit&);

        Trit& operator- (Trit&);

        bool is_overflow();
};


class Tryte
{
    protected:
        QVector<Trit> sequence;
        static const int size = 6;

    public:
        Tryte();

        void display();

        Tryte(unsigned long);

        Trit& operator[] (int);
};


class Trint : public Tryte
{
    public:
        Trint() : Tryte() {}
        Trint(unsigned long n) : Tryte(n) {}

        Trint& operator+ (Trint&);
};

#endif // TERNARY_LOGIC


