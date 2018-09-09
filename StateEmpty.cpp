#include "StateEmpty.h"

/*
 * Constructor
 */
StateEmpty::StateEmpty(Game &g) : State(g)
{
     _stateName = "Empty";
}

/*
 * Destructor
 */
StateEmpty::~StateEmpty()
{

}

/*
 *
 */
void StateEmpty::draw()
{
     cout << "Neimplementovano" << endl;
     cout << "b) back" << endl;
}

/*
 *
 */
void StateEmpty::update()
{

}

/*
 *
 */
void StateEmpty::handleInput(char c)
{
     if(c == 'b')
     {
          _game.setState("Pause");
     }
}

/*
 *
 */
void StateEmpty::enter()
{

}

/*
 *
 */
void StateEmpty::exit()
{

}
