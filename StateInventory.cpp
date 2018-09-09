#include "StateInventory.h"

/*
 * Constructor
 */
StateInventory::StateInventory(Game &g) : State(g)
{
     _stateName = "Inventory";
}

/*
 * Destructor
 */
StateInventory::~StateInventory()
{

}

/*
 *
 */
void StateInventory::draw()
{
     cout << "    OOOOOOOOOOOOOOOOOOOOOOOO0OOOOO" << endl;
     cout << "    O          INVENTORY         O" << endl;
     cout << "    OOOOOOOOOOOOOOOOOOOOOOOO0OOOOO" << endl;
     this->_game._player->drawInventory();

     this->_game._player->inventory()->printPointedItem();

     cout << "1) Equip Item" << endl;
     cout << "2) Use Item" << endl;
     cout << "3) Unequip Item" << endl;
     cout << "4) Drop Item" << endl;

     cout << "b) back" << endl;
}

/*
 *
 */
void StateInventory::update()
{

}

/*
 *
 */
void StateInventory::handleInput(char c)
{
     if(c == 'b')
     {
          _game.setState("Pause");
     }
     if(c == '+')
          _game._player->inventory()->incrementItemPointer();

     if(c == '-')
          _game._player->inventory()->decrementItemPointer();

     if(c == '4')
     {
          _game._player->inventory()->deleteItem(_game._player->inventory()->_pointer);
     }
}

/*
 *
 */
void StateInventory::enter()
{

}

/*
 *
 */
void StateInventory::exit()
{

}
