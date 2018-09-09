#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <assert.h>

#include "Game.h"
#include "Item.h"
#include "Inventory.h"
#include "Armor.h"
#include "Weapon.h"

//using namespace std;

class Game;

class Player
{
public:
          // constructor
          Player(std::string name);
          virtual ~Player();

          Inventory *inventory();

          void move(int y, int x, Game &game);
          void drawPlayer(Game &game);

          std::string name() const;
          char mini() const;

          void drawGold() const;
          void drawHp() const;
          void drawLevel() const;
          void drawStats() const;
          void drawEquip() const;
          void drawInventory() const;

          void addItem(Item &i);
          void deleteItem(int item);

          // set and get HP
          void setHp(int hp);
          int hp() const;

          void setLevel(int level);
          int level() const;

          void setGold(int gold);
          int gold() const;

          // set coords
          void setX(int x);
          void setY(int y);

          void incX();
          void incY();
          void decX();
          void decY();

          // get coords
          int X() const;
          int Y() const;

private:
     char _miniature;

     int _xCoord;
     int _yCoord;

     std::string _name;
     int _hp;
     int _level;
     //int _gold;

     Inventory *_inventory;

     //Equipment _equipment;
     Weapon *_weapon;
     Armor *_armor;
};


#endif
