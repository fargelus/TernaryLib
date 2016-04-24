#include "simple.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    try
    {
        Tryte t(-6);
        Tryte t1 = 0;
        t = t / t1;
        t.display();
    }
    catch (SimpleException& e)
    {
        e.displayEx();
    }

    return 0;
}
