#include "Item.h"

Item::Item() {_type = "Item";}
Item::~Item() {}

void Item::printItem()                  {}
string Item::itemName() const           {return this->_itemName;}
string Item::itemDescription() const    {return this->_itemDescription;}
string Item::itemType() const           {return this->_type;}
int Item::rarity() const                {return this->_rarity;}
int Item::price() const                 {return this->_price;}
double Item::weight() const             {return this->_weight;}
string Item::specific() const           {return this->_itemName;}
