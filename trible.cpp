#include "trible.h"
#include <sstream>
#include <string>
#include <QDebug>

Trible::Trible() : base(baseSize), mantissa(mSize){}

Trible::Trible(float number) : Trible()
{
    // преобразовать number в строку
    std::stringstream ss(std::stringstream::in | std::stringstream::out);
    ss << number;
    std::string numberToString = ss.str();

    bool isInt = false;
    int commaPos = numberToString.find('.');
    if (commaPos == -1)
        isInt = true;

    if (!isInt)
    {
        int countRank = -(numberToString.length() - commaPos - 1);
        ternaryNumber(base, countRank);
        number *= pow(10, abs(countRank));
    }
    ternaryNumber(mantissa, number);
}

void Trible::display()
{
    base.display();
    mantissa.display();
}

Sequence Trible::getBase() const { return base; }

Sequence Trible::getMant() const { return mantissa; }

// меняет порядок мантиссу меньшего числа
Sequence Trible::changeOrder(Trible & rightOp)
{
    int diffBase, minBase, newMant;
    int thisBase = base.convertNumber();
    int rightOpBase = rightOp.getBase().convertNumber();
    Sequence tempMant = rightOp.getMant();

    // меняем порядок и мантиссу правого операнда
    if (thisBase < rightOpBase)
    {
        minBase = thisBase;
        diffBase = abs(thisBase) - abs(rightOpBase);
        newMant = tempMant.convertNumber() * pow(10, diffBase);
        ternaryNumber(tempMant, newMant);
    }
    // меняем порядок и мантиссу нашего числа
    else
    {
       minBase = rightOpBase;
       diffBase = abs(rightOpBase) - abs(thisBase);
       newMant = mantissa.convertNumber() * pow(10, diffBase);
       ternaryNumber(mantissa, newMant);
       ternaryNumber(base, minBase);
    }

    return tempMant;
}

Trible &Trible::operator+(Trible & rightOp)
{
    Sequence tempMant = changeOrder(rightOp);

    mantissa + tempMant;
    return *this;
}

Trible &Trible::operator-(Trible & rightOp)
{
    Sequence tempMant = changeOrder(rightOp);

    mantissa - tempMant;
    return *this;
}

Trible& Trible::operator*(Trible & rightOp)
{
    Sequence tempMant = rightOp.getMant();
    int newBase = 0;

    // если число не целое
    if (base.convertNumber() != 0
            && rightOp.getBase().convertNumber() != 0)
    {
        tempMant = changeOrder(rightOp);
        qDebug() << mantissa.convertNumber();
        // при обычном ум-ии степени складываются
        newBase = base.convertNumber() + rightOp.getBase().convertNumber();
    }
    else
        if (mantissa.convertNumber() != 0
            && rightOp.getBase().convertNumber() != 0)
        newBase = base.convertNumber() < rightOp.getBase().convertNumber()
                ? base.convertNumber() : rightOp.getBase().convertNumber();

    // устанавливаем новую степень
    ternaryNumber(base, newBase);

    Sequence retVal = mantissa * tempMant;
    mantissa = retVal;

    return *this;
}

Trible &Trible::operator/(Trible right)
{
    float number = right.getMant().convertNumber();
    if (number == 0)
        throw SimpleException("Division by zero");

    float exp = pow(10, right.getBase().convertNumber());
    number *= exp;

    float divisor = 1 / number;

    QString sNumber = QString::number(divisor, 'f', 3);
    right = Trible(sNumber.toFloat());
    (*this) * right;

    return *this;
}

