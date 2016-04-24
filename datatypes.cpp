#include "datatypes.h"
#include <QDebug>


Troolean::Troolean(int val)
{
    if (val < -364 || val > 364)
        throw SimpleException("Troolean must be between -364 and 364");
    if (val > 0)
        memory.fill(Trit(POS, 0));
    else if (val == 0)
        memory.fill(Trit(UNKNOWN, 0));
    else
        memory.fill(Trit(NEG, 0));
}

// инверсия
Troolean Troolean::operator~()
{
    Troolean t;
    if (memory[0].getState() == POS)
        t.memory.fill(Trit(NEG, 0));
    else if (memory[0].getState() == NEG)
        t.memory.fill(Trit(POS, 0));
    return t;
}

// операция логическое и
Troolean Troolean::operator&&(Troolean & t)
{
    Troolean tr;
    if (memory[0].getState() == NEG)
        tr = Troolean(-1);
    else if (memory[0].getState() == POS)
    {
        switch(t.memory[0].getState())
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
        switch(t.memory[0].getState())
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

// операция логическое или
Troolean Troolean::operator ||(Troolean & t)
{
    Troolean tr;
    if (memory[0].getState() == POS)
        tr = Troolean(1);
    else if (memory[0].getState() == NEG)
    {
        switch(t.memory[0].getState())
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
        switch(t.memory[0].getState())
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

void Troolean::display()
{
    Tryte::display();
}

std::ostream& operator<<(std::ostream & out, Troolean & t)
{
    if (t.memory[0].getState() == NEG)
        out << "false";
    else if (t.memory[0].getState() == POS)
        out << "true";
    else
        out << "unknown";
    return out;
}



Trint::Trint(int num) : memory(size)
{
    ternaryNumber(memory, num);
}

Trint::Trint(Sequence rightMem) {memory = rightMem;}

Sequence Trint::getSeq() { return memory; }

Trint &Trint::operator+(Trint & rightOp)
{
    Sequence tempSeq = rightOp.getSeq();
    memory + tempSeq;
    return *this;
}

Trint &Trint::operator-(Trint & rightOp)
{
    Sequence tempSeq = rightOp.getSeq();
    memory - tempSeq;
    return *this;
}

Trint Trint::operator *(Trint & rightOp)
{
    Sequence tempSeq = rightOp.getSeq();
    Sequence result;
    result = memory * tempSeq;
    return result;
}

Trint Trint::operator /(Trint & rightOp)
{
    Sequence tempSeq = rightOp.getSeq();
    Sequence result;
    result = memory / tempSeq;
    return result;
}

void Trint::display()
{
    memory.display();
}
