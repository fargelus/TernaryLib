#include "datatypes.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    try
    {
        Trint tr(2);
        Trint tr1 = 3;

        tr = tr / tr1;
        tr.display();
    }
    catch (SimpleException& e)
    {
        e.displayEx();
    }

    return 0;
}
