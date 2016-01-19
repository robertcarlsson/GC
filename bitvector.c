#include "bitvector.h"

uintptr_t create_bitvector_size(size_t size)
{
//Bit thinking:*= any value
    size = size << 3;
    //*|000
        return size;
}

size_t get_bitvector_size(uintptr_t bitvector)
{
    //Decimal 3 = 011
    if (bitvector % 8 == 3) {
        return (bitvector >> 3);
    }
    //should be 111 assert since not implemented
        else {
        assert(false);
    }
    return 0;
}
