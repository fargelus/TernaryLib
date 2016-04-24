#include "datatypes.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    try
    {
        Trint t(100);
        Trint t1 = 10;
        t = t + t1;
        t.display();
    }
    catch (SimpleException& e)
    {
        e.displayEx();
    }

    return 0;
}
