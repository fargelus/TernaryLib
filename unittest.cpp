#include "unittest.h"
#include <QDebug>

void Tribletest::generalTest(Trible& left, Trible& right)
{
    Trible res;
    res = left - right;
    res.display();
    qDebug() << "";

    left = Trible(27.1);
    right = Trible(3.2);
    res = left - right;
    res.display();
    qDebug() << "";

    res = right - left;
    res.display();
    qDebug() << "";

    left = Trible(27.0);
    right = Trible(3.0);
    res = left - right;
    res.display();
    qDebug() << "";

    right  = Trible(3.9);
    res = left - right;
    res.display();
    qDebug() << "";

    left = Trible(27.1);
    right = Trible(3.2);
    res = left - right;
    res.display();
    qDebug() << "";
}

