#ifndef SIMPLE
#define SIMPLE

#include <cstring>
#include <cmath>
#include <iostream>
#include <QVector>

// простейший класс исключений
struct outOfRange
{
    std::string description;
    outOfRange() {description = "Ошибка выход за пределы диапазона";}
    outOfRange(const std::string st) : outOfRange()
    {
        if (!st.empty())
            description = st;
    }
    void displayEx()
    {
        std::cout << description << std::endl;
    }
};

// симметричная с-ма счисления
enum state {NEG = -1, UNKNOWN, POS};

// Trit - это троичный бит, у которого 3 состояния -1, 0, 1
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

        Trit& operator+(Trit&);
        Trit& operator- (Trit&);

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


#endif // SIMPLE

