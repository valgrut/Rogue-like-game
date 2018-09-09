#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>
#include "Item.h"
//#include "Player.h"
//#include "IEquipable.h"

class Armor : public Item //, public IEquipable
{
public:
     Armor();
     Armor(std::string name, std::string description, int price, int rarity, int def, double weight);
     virtual ~Armor();

     virtual void printItem();
     //virtual int specific() const;
     //virtual double weight();

     //virtual void equip(Player &p);
     //virtual void unequip(Player &p);

     int _def;
};

#endif
