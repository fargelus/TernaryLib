#include "unittest.h"
#include <QDebug>

using std::cout;
using std::endl;

void Tribletest::minusTest(Trible& left, Trible& right)
{
    // 1
    cout << left.getMant().convertNumber() << "-" << right.getMant().convertNumber();
    left - right;
    cout << " = " << left.getMant().convertNumber() << endl;
    cout << endl;

    // 2
    left = Trible(30.0);
    right = Trible(3.1);
    cout << left.getMant().convertNumber() << "-" << right.getMant().convertNumber();
    cout << " = ";
    left - right;
    cout << left.getMant().convertNumber() << endl;
    cout << endl;

    // 3
    left = Trible(30.0);
    cout << right.getMant().convertNumber() << "-" << left.getMant().convertNumber();
    right - left;
    cout << " = " << right.getMant().convertNumber() << endl;
    cout << endl;

    // 4
    left = Trible(27.0);
    right = Trible(3.0);
    cout << left.getMant().convertNumber() << "-" << right.getMant().convertNumber();
    left - right;
    cout << " = " << left.getMant().convertNumber() << endl;
    cout << endl;

    // 5
    right  = Trible(3.9);
    cout << left.getMant().convertNumber() << "-" << right.getMant().convertNumber();
    left - right;
    cout << " = " << left.getMant().convertNumber() << endl;
    cout << endl;

    // 6
    left = Trible(27.1);
    right = Trible(3.2);
    cout << left.getMant().convertNumber() << "-" << right.getMant().convertNumber();
    left - right;
    cout << " = " << left.getMant().convertNumber() << endl;
    cout << endl;

    // 7
    left = Trible(0.0);
    right = Trible(3.2);
    cout << left.getMant().convertNumber() << "-" << right.getMant().convertNumber();
    left - right;
    cout << " = " << left.getMant().convertNumber() << endl;
    cout << endl;

    // 8
    left = Trible(3.2);
    right = Trible(0.0);
    cout << left.getMant().convertNumber() << "-" << right.getMant().convertNumber();
    left - right;
    cout << " = " << left.getMant().convertNumber() << endl;
    cout << endl;
}

void Tribletest::multiplyTest(Trible& left, Trible& right)
{
    // 1
    cout << left.getMant().convertNumber() << "*" << right.getMant().convertNumber();
    left * right;
    cout << " = " << left.getMant().convertNumber() << endl;
    cout << endl;

    // 2
    left = Trible(27.2);
    right = Trible(1.6);
    cout << left.getMant().convertNumber() << "*" << right.getMant().convertNumber();
    left * right;
    cout << " = " << left.getMant().convertNumber() << endl;
    cout << endl;

    // 3
    left = Trible(27.2);
    cout << right.getMant().convertNumber() << "*" << left.getMant().convertNumber();
    right * left;
    cout << " = " << right.getMant().convertNumber() << endl;
    cout << endl;

    // 4
    left = Trible(27.0);
    right = Trible(3.0);
    cout << left.getMant().convertNumber() << "*" << right.getMant().convertNumber();
    cout << " = ";
    left * right;
    cout << left.getMant().convertNumber() << endl;
    cout << endl;

    // 5
    right  = Trible(3.9);
    left = Trible(27.0);
    cout << left.getMant().convertNumber() << "*" << right.getMant().convertNumber();
    left * right;
    cout << " = " << left.getMant().convertNumber() << endl;
    cout << endl;

    // 6
    left = Trible(27.1);
    right = Trible(0.32);
    cout << left.getMant().convertNumber() << "*" << right.getMant().convertNumber();
    cout << " = ";
    left * right;
    cout << left.getMant().convertNumber() << endl;
    cout << endl;

    // 7
    left = Trible(0.0);
    right = Trible(3.2);
    cout << left.getMant().convertNumber() << "*" << right.getMant().convertNumber();
    left * right;
    cout << " = " << left.getMant().convertNumber() << endl;
    cout << endl;

    // 8
    left = Trible(3.2);
    right = Trible(0.0);
    cout << left.getMant().convertNumber() << "*" << right.getMant().convertNumber();
    left * right;
    cout << " = " << left.getMant().convertNumber() << endl;
    cout << endl;
}

void Tribletest::divisionTest(Trible &, Trible &)
{

}

