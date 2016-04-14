#include "simple.h"

int Trit::base = 3;

Trit::Trit(state new_state, short new_pos) : overflow(false)
{
    if (new_pos < 0)
        throw outOfRange();
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
    int sum = static_cast<int> (st) + static_cast<int> (t.getState());
    if (sum == 2 || sum == -2)
    {
        overflow = true;
        sum = -1;
    }
    st = static_cast<state> (sum);

    return *this;
}

Trit &Trit::operator-(Trit & t)
{
    int diff = static_cast<int> (st) - static_cast<int> (t.getState());
    if (diff == 2 || diff == -2)
    {
        overflow = true;
        diff = 1;
    }
    st = static_cast<state> (diff);

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
    if (number < -364 || number > 364)
        throw outOfRange("Tryte must be between -364 and 364");
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
        throw outOfRange();
    return sequence[index];
}
