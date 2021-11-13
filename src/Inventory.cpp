#include "Inventory.h"

#include "Weapon.h"
#include "Armor.h"

// constructor
Inventory::Inventory() : _sumWeight(0), _gold(10)
{
     _pointer = 0;
}

// destructor
Inventory::~Inventory()
{
     _inventory.clear();
     std::cerr << "Inventar znicen." << std::endl;
}

void Inventory::addItem(Item &i)
{
     // pridat do vectoru
     this->_inventory.push_back(i);

     // pripocitat weight
     this->_sumWeight += i.weight();

     std::cerr << "Vlozen " << i._itemName << std::endl;
     std::cerr << "V inventari je nyni " << this->_inventory.size() << " veci." << std::endl;
}

void Inventory::deleteItem(int i)
{
     if(i >= 0 && i < _inventory.size())
     {
          // odecist weight
          this->_sumWeight -= _inventory.at(i).weight();

          std::cerr << "Odstranen " << _inventory.at(i)._itemName << std::endl;

          // odstranit z vectoru
          this->_inventory.erase(_inventory.begin() + i);
     }
}

int Inventory::getSumWeight()
{
     return this->_sumWeight;
}

void Inventory::setGold(int gold)
{
     this->_gold = gold;
}

int Inventory::gold() const
{
     return this->_gold;
}

/*
void Inventory::incrementItemPointer()
{
     if(_pointer <_inventory.size()-2)
          _pointer++;
}*/

void Inventory::printPointedItem()
{
     std::cout << std::endl << "ptr: " << _pointer << " (+/-)" << std::endl;

     if(_inventory.size() > 0 && _pointer < _inventory.size())
     {
          //_inventory.at(_pointer).printItem();

          std::cout << "*****************************************************" << std::endl;
          std::cout << "Type: " << _inventory.at(_pointer).itemType() << std::endl;
          std::cout << "Item: " << _inventory.at(_pointer).itemName() << std::endl;
          std::cout << "Description: " << _inventory.at(_pointer).itemDescription() << std::endl;
          std::cout << "Specific value: " << _inventory.at(_pointer).specific() << std::endl;
          std::cout << "Price: " << _inventory.at(_pointer).price() << std::endl;
          std::cout << "*****************************************************" << std::endl;

          //TODO _inventory.at(_pointer).showOptions();
     }
}
