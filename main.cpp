#include "trible.h"
#include <iostream>

using std::cout;
using std::endl;


int main()
{
    try
    {
        Trible t(1.45);
        Trible t1(1.3);

        t = t + t1;
    }
    catch (SimpleException& e)
    {
        e.displayEx();
    }

    return 0;
}
