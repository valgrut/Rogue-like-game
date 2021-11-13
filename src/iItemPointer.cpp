#include "iItemPointer.h"

// destructor
iItemPointer::iItemPointer()
{
}

iItemPointer::~iItemPointer()
{
}

void iItemPointer::incrementItemPointer()
{
     _pointer++;
}

void iItemPointer::decrementItemPointer()
{
     if(_pointer > 0)
          _pointer--;
}
