#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <vector>

#include "iItemPointer.h"
#include "Item.h"
#include "Gold.h"

//using namespace std;

class Inventory : public iItemPointer
{
public:
     Inventory();
     virtual ~Inventory();

     void addItem(Item &i);
     void deleteItem(int item);

     int getSumWeight();
     void setGold(int gold);
     int gold() const;

     void printPointedItem();
     Item& pointedItem(); // TODO get pointed item
     //void incrementItemPointer();

     std::vector<Item> _inventory;
private:
     unsigned int _sumWeight;
     unsigned int _gold;
     Gold _g;
     //unsigned int _capacity;
};

#endif
