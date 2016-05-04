#ifndef DATATYPES
#define DATATYPES

#include "simple.h"

// Troolean - троичный boolean
class Troolean : private Tryte
{
    public:
        Troolean() : Tryte() {}
        Troolean(int);
        Troolean operator~();
        friend std::ostream& operator<<(std::ostream&, Troolean&);
        Troolean operator&&(Troolean&);
        Troolean operator || (Troolean&);
        void display();
};

// Trint - троичное целое число(беззнаковое) в диапазоне от 0 до 728
class Trint
{
    private:
        Sequence memory;
        static const int size = 18;

    public:
        Trint() : memory(size){}
        Trint(int);
        Trint(Sequence);

        Sequence getSeq() const;

        Trint& operator+(Trint&);
        Trint& operator- (Trint&);

        Trint operator *(Trint&);
        Trint operator /(Trint&);

        Trit& operator[](int index);

        static int getSize() { return size; }

        void display();
};

#endif // DATATYPES

