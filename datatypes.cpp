#include "datatypes.h"
#include <QDebug>

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
                Trit temp_obj(POS, 0);
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

Trint &Trint::operator-(Trint & t)
{
    for (int i = size - 1; i >= 0; --i)
    {
        if (i < size - 1)
        {
            if (sequence[i + 1].is_overflow())
            {
                Trit temp_obj(POS, 0);
                sequence[i] = sequence[i] - t[i] - temp_obj;
            }
            else
                sequence[i] = sequence[i] - t[i];
        }
        else
            sequence[i] = sequence[i] - t[i];
    }

    return *this;
}


Troolean::Troolean(int val)
{
    if (val < -364 || val > 364)
        throw outOfRange("Troolean must be between -364 and 364");
    if (val > 0)
        sequence.fill(Trit(POS, 0));
    else if (val == 0)
        sequence.fill(Trit(UNKNOWN, 0));
    else
        sequence.fill(Trit(NEG, 0));
}

