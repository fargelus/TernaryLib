#include "functools.h"
#include <QString>

Trible power(const Trible & number, const Trint & base)
{
    Trible retVal;

    // извлечь числа
    int realBase = base.getSeq().convertNumber();

    int mant = number.getMant().convertNumber();
    float numberBase = pow(10, number.getBase().convertNumber());
    float realNumber = mant * numberBase;

    if (realBase < 0)
    {
        realBase = abs(realBase);
        realNumber = 1 / realNumber;
    }

    float res = 1;
    for (int i = 0; i < realBase; ++i)
        res *= realNumber;

    retVal = Trible(res);

    return retVal;
}


Trible squareRoot(const Trible & number)
{
    Trible retVal;

    int mant = number.getMant().convertNumber();
    float numberBase = pow(10, number.getBase().convertNumber());
    float realNumber = mant * numberBase;

    if (realNumber < 0)
        throw SimpleException("Bad number");

    float eps = 0.001;

    float curr_x = realNumber;
    float prev_x;
    do
    {
        prev_x = curr_x;
        curr_x = 0.5 * (prev_x + realNumber / prev_x);
    } while (abs(realNumber - prev_x * prev_x) > eps);

    QString numberStr = QString::number(curr_x, 'f', 3);
    retVal = Trible(numberStr.toFloat());
    return retVal;
}
