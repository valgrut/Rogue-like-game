#ifndef IITEMPOINTER_H
#define IITEMPOINTER_H

#include <iostream>

class iItemPointer
{
public:
     iItemPointer();
     virtual ~iItemPointer();

     virtual void printPointedItem() = 0;
     void incrementItemPointer();
     void decrementItemPointer();

     int _pointer;
};

#endif
