#ifndef DATATYPES
#define DATATYPES

#include "simple.h"

// Troolean - троичный boolean
class Troolean : public Tryte
{
    public:
        Troolean() : Tryte() {}
        Troolean(int);
};

// Trint - троичное целое число(беззнаковое) в диапазоне от 0 до 728
class Trint : public Tryte
{
    public:
        Trint() : Tryte() {}
        Trint(int n) : Tryte(n) {}

        Trint& operator+(Trint&);
        Trint& operator- (Trint&);
};

#endif // DATATYPES

