#include "simple.h"
#include <QDebug>

int Trit::base = 3;

Trit::Trit(state new_state, short new_pos) : onOverflow(UNKNOWN)
{
    if (new_pos < 0)
        throw SimpleException();
    pos = new_pos;
    st = new_state;
}

int Trit::get_number()
{
    return static_cast<int>(st) * pow(base, pos);
}

state Trit::getState() { return st; }

Trit& Trit::operator+(Trit &t)
{
    int sum = static_cast<int> (st) + static_cast<int> (t.getState());
    onOverflow = UNKNOWN;
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

void Trit::setOverflow(state newSt) { onOverflow = newSt; }


void Sequence::display()
{
        // цикл по коллекции - c++11
        for (Trit& tr: seq)
            std::cout << tr.getState();
        std::cout << std::endl;
}

Trit& Sequence::get(int pos)
{
    if (pos < 0 || pos >= seq.size())
        throw SimpleException();
    return seq[pos];
}

void Sequence::set(Trit tr, int pos)
{
    if (pos < 0 || pos >= seq.size())
        throw SimpleException();
    seq[pos] = tr;
}

void Sequence::fill(Trit newTr) { seq.fill(newTr); }

void Sequence::setSize(int newsz)
{
    bool isOk;
    newsz > 0 ? isOk = true : isOk = false;
    if (!isOk)
        throw SimpleException("Bad size");
    for (int i = 0; i < newsz; ++i)
        seq.push_back(Trit(UNKNOWN, i));
}


Tryte::Tryte() { memory.setSize(size);}

Tryte::Tryte(int number) : Tryte()             // перевод числа в троичку
{
    if (number > 364 || number < -364)
        throw SimpleException("Tryte takes number in range -364 and 364");
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
            memory.set(Trit(NEG, degree), size - degree - 1);
        else
            memory.set(Trit(POS, degree), size - degree - 1);

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

// находит ближайшую степень тройки
int Tryte::findNearestPower(int number)
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

int Tryte::convertNumber()
{
    int sum = 0;
    for (int i = size - 1; i >= 0; --i)
        sum += memory.get(i).get_number();
    return sum;
}

void Tryte::display() { memory.display();}

Trit& Tryte::operator[](int index)
{
    if (index < 0 || index >= size)
        throw SimpleException();
    return memory.get(index);
}

Tryte& Tryte::operator+(Tryte &t)
{
    for (int i = size - 1; i >= 0; --i)
    {
        memory.get(i) + t[i];       // изменение сост-я трита
        if (i < size - 1)
        {
            state tempOverflow = memory.get(i+1).getOverflow();
            // если предыдущее переполнение не равно нулю
            // происходит слож-е
            if (tempOverflow != UNKNOWN)
            {
                Trit tempTrit(tempOverflow, 0);

                // запоминаем текущее переполнение
                state currOverflow = memory.get(i).getOverflow();

                memory.get(i) + tempTrit;         // новое сост-е трита + новое переполнение
                state newOverflow = memory.get(i).getOverflow();
                if (newOverflow + currOverflow == UNKNOWN)
                {
                    currOverflow = UNKNOWN;
                    memory.get(i).setOverflow(currOverflow);
                }
            }
            // иначе оставляем всё как есть
        }
    }

    return *this;
}

Tryte &Tryte::operator-(Tryte & t)
{
    for (int i = size - 1; i >= 0; --i)
    {
        memory.get(i) - t[i];       // изменение сост-я трита
        if (i < size - 1)
        {
            state tempOverflow = memory.get(i+1).getOverflow();
            // если предыдущее переполнение не равно нулю
            // происходит вычит-е
            if (tempOverflow != UNKNOWN)
            {
                Trit tempTrit(tempOverflow, 0);

                // запоминаем текущее переполнение
                state currOverflow = memory.get(i).getOverflow();

                memory.get(i) + tempTrit;         // новое сост-е трита + новое переполнение
                state newOverflow = memory.get(i).getOverflow();
                if (newOverflow + currOverflow == UNKNOWN)
                {
                    currOverflow = UNKNOWN;
                    memory.get(i).setOverflow(currOverflow);
                }
            }
            // иначе оставляем всё как есть
        }
    }

    return *this;
}

Tryte Tryte::operator *(Tryte & t)
{
    int num = t.convertNumber();
    Tryte sum;
    if (num > 0)
        for (int i = 0; i < num; ++i)
        {
//            this->display();
//            sum.display();
            sum = sum + *this;
//            std::cout << std::endl;
        }
    else
    {
        num = abs(num);
        int thisNumb = this->convertNumber();
        Tryte negTrint(-thisNumb);
        for (int i = 0; i < num; ++i)
            sum = sum + negTrint;
    }

    return sum;
}

// целочисленное деление
Tryte Tryte::operator /(Tryte & t)
{
    int thisNumb = this->convertNumber();
    int rightNumb = t.convertNumber();
    if (rightNumb == 0)
        throw SimpleException("Division by zero!!!");
    if (thisNumb < rightNumb &&
            thisNumb > 0 && rightNumb > 0)
        return Tryte();

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
        return Tryte(-count);
    return Tryte(count);
}
