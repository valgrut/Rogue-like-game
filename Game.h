#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

#include "Player.h"
#include "StateMachine.h"
#include "MapManager.h"
#include "Map.h"

using std::cin;
using std::cout;

// forward declaration
class StateMachine;
class Player;

class Game
{
public:
     Game();
     virtual ~Game();
     void startGame();
     void handleInput();
     void render();

     void setMap(std::string mapname);

     void createPlayer(std::string name);

     void setState(std::string s);
     std::string state() const;

     Cell _tmp;
     Map* _current;
     MapManager *_mapManager;
     Player* _player;
     StateMachine *_stateMachine;

private:
     std::string _stav;
};

#endif
