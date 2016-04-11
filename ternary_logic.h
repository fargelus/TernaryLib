/*
 * библиотека для работы с троичной логикой
 * дальше подробное описание всех классов
 *
 *
 *
 * Trit - это троичный бит, у которого 3 состояния 0, 1, 2 - система несимметричная(пока)
 * Tryte - троичный байт, состоящий из 6 тритов
 * Trint - троичное целое число(беззнаковое) в диапазоне от 0 до 728
 */

#ifndef TERNARY_LOGIC
#define TERNARY_LOGIC

#include <cstring>
#include <cmath>
#include <QVector>
#include <iostream>

// простейший класс исключений
struct out_of_range
{
    char* description;
    out_of_range() {strcpy(description, "Ошибка выход за пределы диапазона");}
};

// симметричная с-ма счисления
enum state {NEG = -1, UNKNOWN, POS};

// Trit - это троичный бит, у которого 3 состояния 0, 1, 2
class Trit
{
    private:
        state st;
        short pos;          // позиция числа
        static int base;  // осн-е системы счисления(3)
        bool overflow;  // проверка на переполняемость

    public:
        Trit() : st(UNKNOWN), pos(0), overflow(false) {}

        Trit(state, short);

        unsigned get_number();

        state getState();

        Trit& operator+ (Trit&);

        bool is_overflow();
};

// Tryte - троичный байт, состоящий из 6 тритов
class Tryte
{
    protected:
        QVector<Trit> sequence;
        static const int size = 6;

    public:
        Tryte();

        void display();

        Tryte(int);

        Trit& operator[] (int);

        int findNearestPower(int);
};

// Trint - троичное целое число(беззнаковое) в диапазоне от 0 до 728
class Trint : public Tryte
{
    public:
        Trint() : Tryte() {}
        Trint(unsigned long n) : Tryte(n) {}

        Trint& operator+ (Trint&);
};

#endif // TERNARY_LOGIC


