#include "trible.h"
#include <iostream>
#include "unittest.h"

using std::cout;
using std::endl;


int main()
{
    try
    {
        Trible t(3.2);
        Trible t1(2.2);
//        t = t * t1;
//        t.display();
        Tribletest test;
        test.multiplyTest(t, t1);
        cout << endl;
    }
    catch (SimpleException& e)
    {
        e.displayEx();
    }

    return 0;
}
