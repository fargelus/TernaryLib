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
        short on_overflow;

    public:
        Trit() : st(UNKNOWN), pos(0), overflow(false), on_overflow(0) {}

        Trit(state, short);

        Trit(short);

        unsigned get_number();

        state getState() const;

        Trit& operator+ (const Trit&);

        Trit& operator- (Trit&);

        bool is_overflow();

        short get_on_overflow();
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

        const Trit& operator[] (int);

};


class Trint : public Tryte
{
    public:
        Trint() : Tryte() {}
        Trint(unsigned long n) : Tryte(n) {}

        Trint& operator+ (Trint&);

        Trint& operator-(Trint&);
        Trint& operator* (Trint&);
        Trint& operator/ (Trint&);
};

#endif // TERNARY_LOGIC


