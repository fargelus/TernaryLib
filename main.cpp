#include "ternary_logic.h"

int main()
{
    Trint t(3);
    t.display();

    Trint t1(8);
    t1.display();

    t = t + t1;
    t.display();

    return 0;
}
