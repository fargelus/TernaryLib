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
            state tempOverflow = sequence[i + 1].getOverflow();
            Trit tempTrit(tempOverflow, 0);
            sequence[i] = sequence[i] + t[i];
            state currOverflow = sequence[i].getOverflow();
            sequence[i] = sequence[i] + tempTrit;
            if (tempOverflow + currOverflow == UNKNOWN)
                sequence[i].setOverflow(UNKNOWN);
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
            state tempOverflow = sequence[i + 1].getOverflow();
            Trit tempTrit(tempOverflow, 0);
            sequence[i] = sequence[i] - t[i];
            state currOverflow = sequence[i].getOverflow();
            sequence[i] = sequence[i] + tempTrit;
            if (tempOverflow + currOverflow == UNKNOWN)
                sequence[i].setOverflow(UNKNOWN);
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

Troolean Troolean::operator~()
{
    Troolean t;
    if (sequence[0].getState() == POS)
        t.sequence.fill(Trit(NEG, 0));
    else if (sequence[0].getState() == NEG)
        t.sequence.fill(Trit(POS, 0));
    return t;
}

Troolean Troolean::operator&&(Troolean & t)
{
    Troolean tr;
    if (sequence[0].getState() == NEG)
        tr = Troolean(-1);
    else if (sequence[0].getState() == POS)
    {
        switch(t[0].getState())
        {
            case NEG:
                tr = Troolean(-1);
                break;
            case UNKNOWN:
                tr = Troolean(0);
                break;
            case POS:
                tr = Troolean(1);
                break;
            default:
                break;
        }
    }
    else
    {
        switch(t[0].getState())
        {
            case NEG:
                tr = Troolean(-1);
                break;
            case UNKNOWN:
                tr = Troolean(0);
                break;
            case POS:
                tr = Troolean(0);
                break;
            default:
                break;
        }
    }

    return tr;
}

Troolean Troolean::operator ||(Troolean & t)
{
    Troolean tr;
    if (sequence[0].getState() == POS)
        tr = Troolean(1);
    else if (sequence[0].getState() == NEG)
    {
        switch(t[0].getState())
        {
            case NEG:
                tr = Troolean(-1);
                break;
            case UNKNOWN:
                tr = Troolean(0);
                break;
            case POS:
                tr = Troolean(1);
                break;
            default:
                break;
        }
    }
    else
    {
        switch(t[0].getState())
        {
            case NEG:
                tr = Troolean(0);
                break;
            case UNKNOWN:
                tr = Troolean(0);
                break;
            case POS:
                tr = Troolean(1);
                break;
            default:
                break;
        }
    }

    return tr;
}

std::ostream& operator<<(std::ostream & out, Troolean & t)
{
    if (t.sequence[0].getState() == NEG)
        out << "false";
    else if (t.sequence[0].getState() == POS)
        out << "true";
    else
        out << "unknown";
    return out;
}



