#ifndef DATATYPES
#define DATATYPES

#include "simple.h"

// Troolean - троичный boolean
class Troolean : public Tryte
{
    public:
        Troolean() : Tryte() {}
        Troolean(int);
        Troolean operator~();
        friend std::ostream& operator<<(std::ostream&, Troolean&);
        Troolean operator&&(Troolean&);
        Troolean operator || (Troolean&);
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

