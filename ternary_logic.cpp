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

Trit::Trit(short new_pos) : overflow(false)
{
    if (new_pos < 0)
        throw out_of_range();

    pos = new_pos;
    switch (new_pos % base)
    {
    case 0:
        st = NEG;
        break;
    case 1:
        st = UNKNOWN;
        break;
    case 2:
        st = POS;
        break;
    default:
        break;
    }
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
        sequence.push_back(Trit(NEG, i));
}

void Tryte::display()
{
    // цикл по коллекции - c++11
    for (Trit& tr: sequence)
        std::cout << tr.getState();
    std::cout << std::endl;
}

Tryte::Tryte(unsigned long number) : Tryte()             // перевод числа в троичку
{
    const int divisor = 3;
    int i = size - 1;
    unsigned long mod;

    // непосредственно перевод
    while (number != 0)
    {
        mod = number % divisor;
        sequence[i] = mod;
        i--;
        number /= divisor;
    }
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
