#ifndef SIMPLE
#define SIMPLE

#include <cstring>
#include <cmath>
#include <iostream>
#include <QVector>

// простейший класс исключений
struct SimpleException
{
    std::string description;
    SimpleException() {description = "Ошибка выход за пределы диапазона";}
    SimpleException(const std::string st) : SimpleException()
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
        state onOverflow;

    public:
        Trit() : st(UNKNOWN), pos(0), onOverflow(UNKNOWN) {}

        Trit(state, short);

        int get_number();

        state getState();

        Trit& operator+(Trit&);
        Trit& operator- (Trit&);

        state getOverflow();

        void setOverflow(state);
};

// последовательность тритов
class Sequence
{
    private:
        QVector<Trit> seq;

    public:
        void display();

        Trit& get(int);
        void set(Trit, int);

        void fill(Trit);
        void setSize(int newsz);
};


// Tryte - троичный байт, состоящий из 6 тритов
class Tryte
{
    protected:
        Sequence memory;
        static const int size = 6;

    public:
        Tryte();

        Tryte(int);

        Trit& operator[] (int);

        int findNearestPower(int);

        int convertNumber();

        void display();

        Tryte& operator+(Tryte&);
        Tryte& operator- (Tryte&);

        Tryte operator *(Tryte&);
        Tryte operator /(Tryte&);
};


#endif // SIMPLE

