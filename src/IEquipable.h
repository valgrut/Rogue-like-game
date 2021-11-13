#ifndef IEQUIPABLE_H
#define IEQUIPABLE_H

#include <iostream>
#include "Player.h"
/*
* Interface pro equipnutelne veci
*/

using namespace std;

class IEquipable
{
public:
     virtual void equip(Player &p) = 0;
     virtual void unequip(Player &p) = 0;
     virtual ~IEquipable();

private:

};

#endif
