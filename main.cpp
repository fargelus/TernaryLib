#include "ternary_logic.h"

int main()
{
    Trint t(1);
    t.display();

    Trint t1(5);
    t1.display();

    t = t + t1;
    t.display();

    return 0;
}
