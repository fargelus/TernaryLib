#include "datatypes.h"

int main()
{
    try
    {
        Troolean t(20);
        t.display();

        Trint tr(140);
        Trint tr1 = 12;

        tr = tr - tr1;
        tr.display();
    }
    catch (outOfRange& e)
    {
        e.displayEx();
    }

    return 0;
}
