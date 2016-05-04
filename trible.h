#ifndef TRIBLE
#define TRIBLE

#include "datatypes.h"
#include "simple.h"

// троичное число с плавающей запятой
// соотвеств. обычному числу одинарной точности
class Trible
{
    private:
        Sequence base;
        Sequence mantissa;
        static const int mSize = 15;
        static const int baseSize = 3;

    public:
        Trible();
        Trible(float);
        void display();

        Sequence getBase() const;
        Sequence getMant() const;

        Sequence changeOrder(Trible&);

        Trible& operator+ (Trible&);
        Trible& operator- (Trible&);
        Trible& operator* (Trible&);
        Trible& operator/ (Trible);
};


#endif // TRIBLE

