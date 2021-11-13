#include "Armor.h"

Armor::Armor() : _def(1)
{
     _itemName = "Cloth armor";
     _type = "Armor";
     _itemDescription = "Latkove brneni, lehci nez mithrill.";
     _rarity = 0;
     _price = 0;
     _weight = 0.5;
     //_equipable = false;
}

Armor::Armor(std::string name, std::string description, int price, int rarity, int def, double weight)
     : _def(def)
{
     _itemName = name;
     _type = "Armor";
     _itemDescription = description;
     _rarity = rarity;
     _price = price;
     _weight = weight;
     //_equipable = true;
}

Armor::~Armor()
{
}

void Armor::printItem() // overrides
{
     std::cout << "Armor: " << this->_itemName << std::endl;
     std::cout << "Description: " << this->_itemDescription << std::endl;
     //std::cout << "Rarity: " << this->_rarity << std::endl;
     std::cout << "Price: " << this->_price << std::endl;
     std::cout << "Defence: " << this->_def << std::endl;
     //std::cout << "Weight: " << this->_weight << " Kg" << std::endl;
}
/*
int Armor::specific() const
{
     return _def;
}
*/
/*
void Armor::equip(Player &p)
{

}

void Armor::unequip(Player &p)
{

}
*/

//double Armor::weight() {return this->_weight;}
