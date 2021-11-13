#ifndef GOLD_H
#define GOLD_H

#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class Gold : public Item
{
public:
     Gold();
     Gold(int gold, int silver, int copper);
     virtual ~Gold();

     //string itemName() const;

     int getGold() const;
     int getSilver() const;
     int getCopper() const;

     void addGold(int g);
     void addSilver(int s);
     void addCopper(int c);
     void addAmount(int g, int s, int c);

     //virtual int specific() const;

     void drawAmount() const;
     void recount();

     int _gold;
     int _silver;
     int _copper;
};

#endif
