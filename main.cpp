#include "datatypes.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    try
    {
        Trint t;
        t.display();
    }
    catch (SimpleException& e)
    {
        e.displayEx();
    }

    return 0;
}
