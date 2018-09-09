#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
     Item();
     virtual ~Item();

     virtual void printItem();

     virtual string itemName() const;
     virtual string itemDescription() const;
     virtual string itemType() const;
     virtual int price() const;
     virtual int rarity() const;
     virtual double weight() const;
     virtual string specific() const;

     string _itemName;
     string _itemDescription;
     string _type;
     int _price;
     int _rarity;
     double _weight;
};

#endif
