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

        float get_number();

        state getState();
        short getPos() { return pos; }

        Trit& operator+(Trit&);
        Trit& operator- (Trit&);

        state getOverflow();

        void setOverflow(state);
};

// находит ближайшую степень тройки
int findNearestNumber(int);

// последовательность тритов
class Sequence
{
    protected:
        QVector<Trit> seq;

    public:
        Sequence();
        Sequence(int);

        void display();

        int getSize() {return seq.size();}

        void fill(Trit);
        void makeEmpty();

        int convertNumber();
        void setOverToNull();

        Sequence& operator+(Sequence&);
        Sequence& operator- (Sequence&);

        Sequence operator *(Sequence&);
        Sequence operator /(Sequence&);

        Trit& operator[] (int);

        friend void ternaryNumber(Sequence&, int);
};


// Tryte - троичный байт, состоящий из 6 тритов
class Tryte
{
    protected:
        static const int size = 6;
        Sequence memory;

    public:
        Tryte() : memory(size){}
        Tryte(int);
        Tryte(Sequence);

        Sequence getSeq();
        void display();

        Tryte& operator+(Tryte&);
        Tryte& operator- (Tryte&);

        Tryte operator *(Tryte&);
        Tryte operator /(Tryte&);
};


#endif // SIMPLE

