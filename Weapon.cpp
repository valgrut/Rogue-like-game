#include "Weapon.h"

Weapon::Weapon() : _dmg(2)
{
     _itemName = "Hand";
     _type = "Weapon";
     _itemDescription = "Rana pesti muze byt nekdy lepsi nez mec.";
     _rarity = 0;
     _price = 0;
     _weight = 0;
     //_equipped = false;
     //_equipable = false;
}

Weapon::Weapon(string name, string description, int price, int rarity, int dmg, double weight)
     : _dmg(dmg)
{
     //Item::Item();
     _itemName = name;
     _type = "Weapon";
     _itemDescription = description;
     _rarity = rarity;
     _price = price;
     _weight = weight;
     //_equipped = false;
     //_equipable = true;
}

Weapon::~Weapon()
{
}

/*
void Weapon::equip(Player &p)
{
     p._weapon = this;
     // TODO odstranit z inventare
}

void Weapon::unequip(Player &p)
{
     p._weapon = NULL;
     p._inventory->_inventory.push_back(this);
}
*/
/*
int Weapon::specific() const
{
     return _dmg;
}
*/

void Weapon::printItem() // overrides
{
     cout << "Weapon: " << this->_itemName << endl;
     cout << "Description: " << this->_itemDescription << endl;
     //cout << "Rarity: " << this->_rarity << endl;
     cout << "Price: " << this->_price << endl;
     cout << "DMG: " << this->_dmg << endl;
     //cout << "Weight: " << this->_weight << endl;
}

//double Weapon::weight() {return this->_weight;}
