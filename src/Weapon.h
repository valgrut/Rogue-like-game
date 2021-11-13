#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include "Item.h"
//#include "IEquipable.h"

class Weapon : public Item //, public IEquipable
{
public:
     Weapon();
     Weapon(string name, string description, int price, int rarity, int dmg, double weight);
     virtual ~Weapon();

     //virtual void equip(Player &p);
     //virtual void unequip(Player &p);

     virtual void printItem();
     //virtual int specific() const;

     //virtual double weight();

     int _dmg;
};

#endif
