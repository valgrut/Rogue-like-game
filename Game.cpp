#include "Game.h"

Game::Game()
{
     this->_stateMachine = new StateMachine(*this);
     _stav = "Start";

     this->_mapManager = new MapManager();
     setMap("Base");

     // nacist hrace se jmenem "xyz"
     this->_player = NULL;

     /***************************** TEST ***********************************/
     Gold g(3, 32, 91);
     Weapon w;
     Armor r("Mithrill Armor", "Popis", 0, 0, 0, 100);
     this->_current->placeItemTo(3,3, '?', w);
     this->_current->placeItemTo(4,7, '?', w);
     this->_current->placeItemTo(4,5, '?', r);
     this->_current->placeItemTo(6,7, '$', g);
}

Game::~Game()
{
     delete this->_mapManager;
     delete this->_stateMachine;
     delete this->_player;
     this->_current = NULL;
     this->_player = NULL;

     cerr << "Game je znicena" << endl;
}

/*
 * Funkce vykresluje hru do okna na zaklade aktualniho stavu hry
 */
void Game::render()
{
     system("clear");

     // na zaklade aktualniho stavu se vykresli prislusny obsah
     _stateMachine->current()->draw();
}

/*
 * Nastavi mapu jako aktivni
 */
void Game::setMap(std::string mapname)
{
     _current = _mapManager->getMap(mapname);
}

/*
 * Vytvori hrace
 * TODO dle jmena nacte ulozeni
 */
void Game::createPlayer(std::string name)
{
     _player = new Player(name);
}

/*
 * Prepne stav hry na novy stav
 */
void Game::setState(std::string s)
{
     this->_stateMachine->change(s);
}

/*
 * Vrati aktualni stav hry
 */
std::string Game::state() const
{
     return this->_stateMachine->current()->stateName();
}
