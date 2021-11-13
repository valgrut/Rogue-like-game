#include "Gold.h"

Gold::Gold() : _gold(0), _silver(0), _copper(5)
{
     this->_itemName = "Gold";
}

Gold::Gold(int gold, int silver, int copper) : _gold(gold), _silver(silver), _copper(copper)
{
     this->_itemName = "Gold";
}

Gold::~Gold()
{}

/*
string Gold::itemName() const
{
     drawAmount();
     Item::itemName();
}
*/

/*
int Gold::specific() const
{
     return _gold;
}
*/

int Gold::getGold() const
{
     return this->_gold;
}

int Gold::getSilver() const
{
     return this->_silver;
}

int Gold::getCopper() const
{
     return this->_copper;
}

void Gold::addGold(int g)
{
     this->_gold += g;
}
void Gold::addSilver(int s)
{
     this->_silver += s;
}
void Gold::addCopper(int c)
{
     this->_copper += c;
}
void Gold::addAmount(int g, int s, int c)
{
     addGold(g);
     addSilver(s);
     addCopper(c);
}

void Gold::drawAmount() const
{
     cout << "g: " << getGold() << endl;
     cout << "s: " << getSilver() << endl;
     cout << "c: " << getCopper() << endl;
}

void Gold::recount()
{
     int newSilver = _copper / 100;
     _silver += newSilver;
     _copper -= newSilver * 100;

     int newGold = _silver / 100;
     _gold += newGold;
     _silver -= newGold * 100;
}
