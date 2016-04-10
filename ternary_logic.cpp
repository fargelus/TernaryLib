#include "ternary_logic.h"

int Trit::base = 3;

Trit::Trit(state new_state, short new_pos) : overflow(false), on_overflow(0)
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

state Trit::getState() const { return st; }

Trit &Trit::operator+(const Trit &t)
{
    on_overflow = static_cast<short> (st) + static_cast<short> (t.getState());
    if (on_overflow >= 3)
    {
        overflow = true;
        on_overflow %= 3;
        st = static_cast<state>(on_overflow);
    }
    else
        on_overflow = 0;
    return *this;
}

bool Trit::is_overflow()
{ return overflow; }

short Trit::get_on_overflow() { return on_overflow; }


Tryte::Tryte()
{
    for (int i = 0; i < size; ++i)
        sequence.push_back(Trit(NEG, i));
}

void Tryte::display()
{
    for (Trit& tr: sequence)
        std::cout << tr.getState();
    std::cout << std::endl;
}

Tryte::Tryte(unsigned long number) : Tryte()             // перевод числа в троичку
{
    const int divisor = 3;
    int i = size - 1;
    unsigned long mod;
    while (number != 0)
    {
        mod = number % divisor;
        sequence[i] = mod;
        i--;
        number /= divisor;
    }
}

const Trit &Tryte::operator[](int index)
{ return sequence.at(index); }


Trint &Trint::operator+(Trint &t)
{
    for (int i = size - 1; i >= 0; --i)
    {
        if (i < size - 1)
        {
            if (sequence[i + 1].is_overflow())
                sequence[i] = sequence[i] + t[i] + (sequence[i + 1].get_on_overflow() % 3);
            else
                sequence[i] = sequence[i] + t[i];
        }
        else
            sequence[i] = sequence[i] + t[i];
    }

    return *this;
}
