#include "unittest.h"

using std::cout;
using std::endl;

void Tribletest::minusTest()
{
    Trible left(27.0);
    Trible right = 9.0;

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

void Tribletest::multiplyTest()
{
    Trible left(27.0);
    Trible right = 9.0;

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

void Tribletest::divisionTest()
{
    Trible left(27.0);
    Trible right = 9.0;

    // 1 -- обычное дел-е
    left / right;
    cout << left.getMant().convertNumber() << endl;
    left.display();
    cout << endl;

    // 2 -- целое на целое
    left = Trible(76.0);
    right = Trible(12.0);
    left / right;
    cout << left.getMant().convertNumber() << endl;
    left.display();
    cout << endl;

    // 3 -- дробное на целое
    left = Trible(76.23);
    right = Trible(12.0);
    right / left;
    cout << right.getMant().convertNumber() << endl;
    right.display();
    cout << endl;

    // 4 -- целое на дробное
    left = Trible(27.0);
    right = Trible(9.12);
    left / right;
    cout << left.getMant().convertNumber() << endl;
    left.display();
    cout << endl;

    // 5 -- дробное на дробное (<1) тест не пройден
    right  = Trible(3.9);
    left = Trible(27.2);
    left / right;
    cout << left.getMant().convertNumber() << endl;
    left.display();
    cout << endl;

    // 6 -- дробное на дробное(>1) right < 1 тест не пройден
    left = Trible(27.1);
    right = Trible(0.32);
    left / right;
    cout << left.getMant().convertNumber() << endl;
    left.display();
    cout << endl;

    // 7 -- ноль на дробное
    left = Trible(0.0);
    right = Trible(3.2);
    left / right;
    cout << left.getMant().convertNumber() << endl;
    left.display();
    cout << endl;

    // 8 -- деление на ноль
    left = Trible(3.2);
    right = Trible(0.0);
    cout << left.getMant().convertNumber() << "/" << right.getMant().convertNumber();
    left / right;
    cout << " = " << left.getMant().convertNumber() << endl;
    cout << endl;
}



void FuncTest::powerTest()
{
    // 1 -- простой тест
    Trible floatNumber = 3.0;
    Trint base = 2;
    Trible res;

    // результат: 9.0
    res = power(floatNumber, base);
    cout << res.getMant().convertNumber() << endl;
    res.display();
    cout << endl << endl;

    // 2 -- возводим отрицательное число в 2n
    floatNumber = Trible(-3.0);

    // результат: 9.0
    res = power(floatNumber, base);
    cout << res.getMant().convertNumber() << endl;
    res.display();
    cout << endl << endl;

    // 3 -- возводим отрицательное число в n
    base = Trint(3);

    // результат: -27
    res = power(floatNumber, base);
    cout << res.getMant().convertNumber() << endl;
    res.display();
    cout << endl << endl;

    // 4 -- возводим в степень 0
    base = Trint(0);

    // результат: 1
    res = power(floatNumber, base);
    cout << res.getMant().convertNumber() << endl;
    res.display();
    cout << endl << endl;

    // 5 -- возводим 0
    floatNumber = Trible(0.0);
    base = Trint(100);

    // результат: 0
    res = power(floatNumber, base);
    cout << res.getMant().convertNumber() << endl;
    res.display();
    cout << endl << endl;

    // 6 -- отрицательная степень
    floatNumber = Trible(3.0);
    base = Trint(-1);

    // результат: 0.33
    res = power(floatNumber, base);
    cout << res.getMant().convertNumber() << endl;
    res.display();
    cout << endl << endl;

    // 7 -- отрицательная степень
    floatNumber = Trible(-3.0);
    base = Trint(-1);

    // результат: -0.33
    res = power(floatNumber, base);
    cout << res.getMant().convertNumber() << endl;
    res.display();
    cout << endl << endl;

    // 8 -- дробное в степень
    floatNumber = Trible(0.5);
    base = Trint(3);

    // результат: 0.125
    res = power(floatNumber, base);
    cout << res.getMant().convertNumber() << endl;
    res.display();
    cout << endl << endl;
}

void FuncTest::squareRootTest()
{
    // 1 -- простой тест
    Trible number = 4.0;
    Trible res;

    // результат: 2
    res = squareRoot(number);
    cout << res.getMant().convertNumber() << endl;
    res.display();
    cout << endl << endl;

    // 2 -- корень из отрицател. числа
    try
    {
        number = Trible(-4.0);
        res = squareRoot(number);
    }
    catch(SimpleException& s)
    {
        s.displayEx();
    }

    // 3 -- корень из дробного числа
    number = Trible(5.0);

    // результат: ~2.236
    res = squareRoot(number);
    cout << res.getMant().convertNumber() << endl;
    res.display();
    cout << endl << endl;

    // 4 -- корень из дробного числа
    number = Trible(2.2);

    // результат: ~1.483
    res = squareRoot(number);
    cout << res.getMant().convertNumber() << endl;
    res.display();
    cout << endl << endl;

    // 5 -- число < 1
    number = Trible(0.81);

    // результат: 0.9
    res = squareRoot(number);
    cout << res.getMant().convertNumber() << endl;
    res.display();
    cout << endl << endl;

}


