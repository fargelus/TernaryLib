#include "datatypes.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    try
    {
//        Troolean t(0);

        Trint tr(3);
        Trint tr1 = 4;

        tr = tr + tr1;
        tr.display();

//        t.display();
//        t = ~t;
//        t.display();
//        cout << t << endl;

//        Troolean testLogic = 1;
//        Troolean rightOps = 0;

//        testLogic = testLogic && rightOps;
//        cout << testLogic << endl;
    }
    catch (outOfRange& e)
    {
        e.displayEx();
    }

    return 0;
}
