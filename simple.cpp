#include "simple.h"
#include <QDebug>

int Trit::base = 3;

Trit::Trit(state new_state, short new_pos) : onOverflow(UNKNOWN)
{
    // if (new_pos < 0)
        // throw SimpleException();
    pos = new_pos;
    st = new_state;
}

float Trit::get_number()
{
    return static_cast<int>(st) * pow(base, pos);
}

state Trit::getState() { return st; }

Trit& Trit::operator+(Trit &t)
{
    int sum = static_cast<int> (st) + static_cast<int> (t.getState());
    // onOverflow = UNKNOWN;
    if (sum == 2 || sum == -2)
    {
        if (sum == 2)
        {
            onOverflow = POS;
            sum = -1;
        }
        else
        {
            onOverflow = NEG;
            sum = 1;
        }
    }
    st = static_cast<state> (sum);
    return *this;
}

Trit &Trit::operator-(Trit & t)
{
    int diff = static_cast<int> (st) - static_cast<int> (t.getState());
    if (diff == 2 || diff == -2)
    {
        if (diff == -2)
        {
            onOverflow = NEG;
            diff = 1;
        }
        else
        {
            onOverflow = POS;
            diff = -1;
        }
    }
    st = static_cast<state> (diff);

    return *this;
}

state Trit::getOverflow() { return onOverflow;}

void Trit::setOverflow(state over) { onOverflow = over; }


// находит ближайшую степень тройки
int findNearestPower(int number)
{
    int n = 0, tempVal, over, prevSum = 0;
    while (true)
    {
        tempVal = pow(3, n);
        if (tempVal > abs(number))
        {
            over = abs(number) - pow(3, n - 1);
            int counter = n - 2;
            while (counter >= 0)
            {
                prevSum += pow(3, counter);
                counter--;
            }
            if (over <= prevSum)
                n--;
            break;
        }
        n++;
    }

    return n;
}

// перевод числа в троичку
void ternaryNumber(Sequence& s, int number)
{
    s.makeEmpty();
    int size = s.seq.size();
    double rangeUp = floor(pow(3, s.seq.size()) / 2);
    if (number > rangeUp || number < -rangeUp)
        throw SimpleException("range error");
    if (number == 0)
        return;

    int degree, tempVal;
    bool isT = false;
    if (number < 0)
        isT = true;
    do
    {
        degree = findNearestPower(number);

        if (isT)
            s.seq[size - degree - 1] = Trit(NEG, degree);
        else
            s.seq[size - degree - 1] = Trit(POS, degree);

        tempVal = pow(3, degree);
        if (abs(number) >= abs(tempVal))
            number = abs(number) - abs(tempVal);
        else
        {
            number = abs(tempVal) - abs(number);
            isT = !isT;
        }
    }
    while (number != 0);
}

Sequence::Sequence()
{}

Sequence::Sequence(int size)
{
    bool isOk = size > 0 ? true: false;
    if (!isOk)
        throw SimpleException("Bad size");
    for (int i = size - 1; i >= 0; --i)
        seq.push_back(Trit(UNKNOWN, i));
}

void Sequence::display()
{
        bool flag = false;
        // цикл по коллекции - c++11
        for (Trit& tr: seq)
        {
            if (tr.getState() == POS)
                flag = true;
            if (flag)
                std::cout << tr.getState();
        }
//        std::cout << std::endl;
}


void Sequence::fill(Trit newTr) { seq.fill(newTr); }

void Sequence::makeEmpty()
{
    int size = seq.size();
    int j = 0;
    for (int i = size - 1; i >= 0; --i)
        seq[i] = Trit(UNKNOWN, j++);
}

// преобразует число
int Sequence::convertNumber()
{
    int sum = 0;
    int size = seq.size();
    for (int i = size - 1; i >= 0; --i)
        sum += seq[i].get_number();
    return sum;
}

void Sequence::setOverToNull()
{
    for(Trit& tr:seq)
        tr.setOverflow(UNKNOWN);
}


Sequence &Sequence::operator+(Sequence & t)
{
    int size = seq.size();
    for (int i = size - 1; i >= 0; --i)
    {
        seq[i] + t[i];       // изменение сост-я трита
        if (i < size - 1)
        {
            state tempOverflow = seq[i+1].getOverflow();
            // если предыдущее переполнение не равно нулю
            // происходит слож-е
            if (tempOverflow != UNKNOWN)
            {
                Trit tempTrit(tempOverflow, 0);

                // запоминаем текущее переполнение
                state currOverflow = seq[i].getOverflow();

                seq[i] + tempTrit;         // новое сост-е трита + новое переполнение
                state newOverflow = seq[i].getOverflow();
                if (newOverflow + currOverflow == UNKNOWN)
                {
                    currOverflow = UNKNOWN;
                    seq[i].setOverflow(currOverflow);
                }
            }
            // иначе оставляем всё как есть
        }
    }

    return *this;
}

Sequence &Sequence::operator-(Sequence & t)
{
    int size = seq.size();
    for (int i = size - 1; i >= 0; --i)
    {
        seq[i] - t[i];       // изменение сост-я трита
        if (i < size - 1)
        {
            state tempOverflow = seq[i+1].getOverflow();
            // если предыдущее переполнение не равно нулю
            // происходит вычит-е
            if (tempOverflow != UNKNOWN)
            {
                Trit tempTrit(tempOverflow, 0);

                // запоминаем текущее переполнение
                state currOverflow = seq[i].getOverflow();

                seq[i] + tempTrit;         // новое сост-е трита + новое переполнение
                state newOverflow = seq[i].getOverflow();
                if (newOverflow + currOverflow == UNKNOWN)
                {
                    currOverflow = UNKNOWN;
                    seq[i].setOverflow(currOverflow);
                }
            }
            // иначе оставляем всё как есть
        }
    }

    return *this;
}

Sequence Sequence::operator *(Sequence& t)
{
    int num = t.convertNumber();
    Sequence sum(this->seq.size());
    if (num < 0)
    {
        num = abs(num);
        int thisNumb = this->convertNumber();
        ternaryNumber(*this, -thisNumb);
    }

    for (int i = 0; i < num; ++i)
    {
//            std::cout << sum.convertNumber() << std::endl;
//            std::cout << this->convertNumber() << std::endl;
//            std::cout << std::endl;
            sum + *this;
//            std::cout << std::endl;
            sum.setOverToNull();
    }
//    std::cout << sum.convertNumber() << std::endl;

    return sum;
}

// целочисленное деление
Sequence Sequence::operator /(Sequence& t)
{
    Sequence returnVal(this->seq.size());
    int thisNumb = this->convertNumber();
    int rightNumb = t.convertNumber();
    if (rightNumb == 0)
        throw SimpleException("Division by zero!!!");
    if (thisNumb < rightNumb &&
            thisNumb > 0 && rightNumb > 0)
        return returnVal;

    int count = 0;
    bool isMinus = false;

    if (thisNumb * rightNumb < 0)
        isMinus = true;

    thisNumb = abs(thisNumb);
    rightNumb = abs(rightNumb);
    do
    {
        thisNumb -= rightNumb;
        count++;
    } while (thisNumb >= rightNumb);

    if (isMinus)
        ternaryNumber(returnVal, -count);
    else
        ternaryNumber(returnVal, count);
    return returnVal;
}

Trit &Sequence::operator[](int index)
{
    int size = seq.size();
    if (index < 0 || index >= size)
        throw SimpleException();
    return seq[index];
}



Tryte::Tryte(int number) : memory(size)
{
    ternaryNumber(memory, number);
}

Tryte::Tryte(Sequence rightMem) { memory = rightMem;}

Sequence Tryte::getSeq() { return memory;}

void Tryte::display() { memory.display();}

Tryte &Tryte::operator+(Tryte & tr)
{
    Sequence tempSeq = tr.getSeq();
    memory + tempSeq;
    return *this;
}

Tryte &Tryte::operator-(Tryte & tr)
{
    Sequence tempSeq = tr.getSeq();
    memory - tempSeq;
    return *this;
}

Tryte Tryte::operator *(Tryte & tr)
{
    Sequence tempSeq = tr.getSeq();
    Sequence result;
    result = memory * tempSeq;
    return result;
}

Tryte Tryte::operator /(Tryte & tr)
{
    Sequence tempSeq = tr.getSeq();
    Sequence result;
    result = memory / tempSeq;
    return result;
}

