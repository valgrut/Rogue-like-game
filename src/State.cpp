#include "State.h"

/*
 * Constructor
 */
State::State(Game &g) : _game(g)
{

}
State::State(const State& src) : _game(src._game)
{

}

/*
 * Destructor
 */
State::~State()
{
     cerr << "Stav " << _stateName << " znicen" << endl;
}

/*
 *
 */
void State::update()
{
     //DELETE TODO ????????
     // nebo implementovat
}

/*
 *
 */
void State::handleInput(char c)
{
     /*
     if(c == 'b')
     {
          _game.setState("Pause");
     }
     */
}

/*
 *
 */
void State::enter()
{
     //DELETE TODO ????????
     // nebo implementovat
}

/*
 *
 */
void State::exit()
{
     //DELETE TODO ????????
     // nebo implementovat
}
