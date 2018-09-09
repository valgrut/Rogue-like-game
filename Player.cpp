#include "Player.h"

/*
 * Konstruktor
 * Vytvori objekty v objektu Player a inicializuje hodnoty
 */
Player::Player(std::string name) : _hp(10), _name(name), _xCoord(1), _yCoord(1), _miniature('@'), _level(1)
{
     this->_inventory = new Inventory();

     // pouze pro testovani:
     this->_weapon = new Weapon();
     this->_armor = new Armor();
}

/*
 * Destruktor
 * Dealokuje dynamicky alokovane cleny
 */
Player::~Player()
{
     delete _inventory;
     _inventory = NULL;

     delete _weapon;
     delete _armor;

     cerr << "Player " << name() << " znicen" << endl;
}

/*
 * Vrati ukazatel na hracuv inventar
 */
Inventory *Player::inventory() {return this->_inventory;}

/*
 * Pohyb po mape
 * @y: 1,0,-1  udava pocet policek, o ktery se hrac pohne po ose y
 * @x: 1,0,-1  udava pocet policek, o ktery se hrac pohne po ose x
 */
void Player::move(int y, int x, Game &game)
{
	assert(y >= -1 && y <= 1);
	assert(x >= -1 && x <= 1);

     // lambda expression - detekce kolize se zdi (Wall)
     auto isWall = [](char c) -> bool {return c=='#';};

	if(!isWall(game._current->cellAt(game._player->X() + x, game._player->Y() + y).cell() ) )
	{
		game._current->setCellAt(game._player->X(), game._player->Y(), game._tmp);

		game._tmp = game._current->cellAt(game._player->X() + x, game._player->Y() + y);

		if(y < 0) game._player->decY(); if(y > 0) game._player->incY();
		if(x < 0) game._player->decX(); if(x > 0) game._player->incX();

		drawPlayer(game);
	}
}

/*
 * Nastavi pozici na mape, na obrazek hrace '@'
 */
void Player::drawPlayer(Game &game)
{
     Cell newCell('@');
     game._current->setCellAt(game._player->X(), game._player->Y(), newCell);
}

/*
 * get Player's name
 */
std::string Player::name() const
{
     return this->_name;
}

/*
 * get player's miniature
 */
char Player::mini() const
{
     return this->_miniature;
}

/*
 * set HP
 */
void Player::setHp(int hp)
{
     this->_hp = hp;
}

/*
 * get HP
 */
int Player::hp() const
{
     return this->_hp;
}

/*
 * Vykresli HP
 */
void Player::drawHp() const
{
     int n = _hp; // %10
     cout << "HP: ";
     if(n > 0)
     {
         for(int i = 0; i < n; i++)
         cout << '#';
     }
     else
     {
          cout << "DEAD";
     }
     cout << endl;
}

/*
 * Vykresli Zlato
 */
void Player::drawGold() const
{
     cout << "Gold: " << this->_inventory->gold() << endl;
}

/*
 * Vykresli Level
 */
void Player::drawLevel() const
{
     cout << "Level: " << this->level() << endl;
}

/*
 * Vykresli aktualni equip
 */
void Player::drawEquip() const
{
     cout << "Equipped: " << endl;
     if(_weapon != NULL)
          _weapon->printItem();
     if(_armor != NULL)
          _armor->printItem();
}

/*
 * Vykresli polozky inventare
 */
void Player::drawInventory() const
{
     if(_inventory->_inventory.empty())
          cout << "Inventory is empty." << endl;

     int ptr = 0;
     for(auto it = _inventory->_inventory.begin(); it != _inventory->_inventory.end(); ++it)
     {
          cout << ptr << ": " << it->_itemName << endl;
          ptr++;
     }
}

/*
 * Vykresli Staty hrace
 */
void Player::drawStats() const
{
     drawHp();
     drawLevel();
     drawGold();
}

/*
 * Vlozi do inventare Item
 */
void Player::addItem(Item &i)
{
     _inventory->addItem(i);
}

/*
 * Smaze z inventare Item na zadane pozici
 */
void Player::deleteItem(int item)
{
     _inventory->deleteItem(item);
}

void Player::setLevel(int level)
{
     this->_level = level;
}

int Player::level() const
{
     return this->_level;
}

void Player::setGold(int gold)
{
     if(_inventory != NULL)
          this->_inventory->setGold(gold);
}

int Player::gold() const
{
     if(_inventory != NULL)
          return this->_inventory->gold();
}

// set coords
void Player::setX(int x) {this->_xCoord = x;}
void Player::setY(int y) {this->_yCoord = y;}

void Player::incX() {this->_xCoord++;}
void Player::incY() {this->_yCoord++;}

void Player::decX() {this->_xCoord--;}
void Player::decY() {this->_yCoord--;}

// get coords
int Player::X() const {return this->_xCoord;}
int Player::Y() const {return this->_yCoord;}
