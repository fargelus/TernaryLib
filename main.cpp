#include "ternary_logic.h"

int main()
{
    try
    {
        Troolean t(-370);
        t.display();
    }
    catch (outOfRange& e)
    {
        e.displayEx();
    }

    return 0;
}
