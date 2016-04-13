#include "ternary_logic.h"
#include <QDebug>
#include <cassert>

int Trit::base = 3;

Trit::Trit(state new_state, short new_pos) : overflow(false)
{
    if (new_pos < 0)
        throw out_of_range();
    pos = new_pos;
    st = new_state;
}

unsigned Trit::get_number()
{
    return static_cast<unsigned>(st) * pow(base, pos);
}

state Trit::getState() { return st; }

Trit& Trit::operator+(Trit &t)
{
    short sum = static_cast<short> (st) + static_cast<short> (t.getState());
    if (sum >= 3)
    {
        overflow = true;
        sum %= 3;
    }
    st = static_cast<state> (sum);

    return *this;
}

bool Trit::is_overflow()
{ return overflow; }



Tryte::Tryte()
{
    for (int i = 0; i < size; ++i)
        sequence.push_back(Trit(UNKNOWN, i));
}

void Tryte::display()
{
    // цикл по коллекции - c++11
    for (Trit& tr: sequence)
        std::cout << tr.getState();
    std::cout << std::endl;
}

Tryte::Tryte(int number) : Tryte()             // перевод числа в троичку
{
    int degree, tempVal;
    bool isT = false;
    if (number < 0)
        isT = true;
    do
    {
        degree = findNearestPower(number);

        if (isT)
            sequence[size - degree - 1] = Trit(NEG, degree);
        else
            sequence[size - degree - 1] = Trit(POS, degree);

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


Trit& Tryte::operator[](int index)
{
    if (index < 0 || index >= size)
        throw out_of_range();
    return sequence[index];
}


// операция сложения двух троичных целых
// чисел
Trint &Trint::operator+(Trint &t)
{
    for (int i = size - 1; i >= 0; --i)
    {
        if (i < size - 1)
        {
            if (sequence[i + 1].is_overflow())
            {
                Trit temp_obj(UNKNOWN, 0);      // FIX THIS
                sequence[i] = sequence[i] + t[i] + temp_obj;
            }
            else
                sequence[i] = sequence[i] + t[i];
        }
        else
            sequence[i] = sequence[i] + t[i];
    }

    return *this;
}
