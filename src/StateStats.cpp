#include "StateStats.h"

/*
 * Constructor
 */
StateStats::StateStats(Game &g) : State(g)
{
     _stateName = "Stats";
}

/*
 * Destructor
 */
StateStats::~StateStats()
{

}

/*
 *
 */
void StateStats::draw()
{
     cout << "    OOOOOOOOOOOOOOOOOOOOOOOO0OOOOO" << endl;
     cout << "    O            STATS           O" << endl;
     cout << "    OOOOOOOOOOOOOOOOOOOOOOOO0OOOOO" << endl;
     this->_game._player->drawStats();
     cout << "b) back" << endl;
}

/*
 *
 */
void StateStats::update()
{

}

/*
 *
 */
void StateStats::handleInput(char c)
{
     if(c == 'b')
     {
          _game.setState("Pause");
     }
}

/*
 *
 */
void StateStats::enter()
{

}

/*
 *
 */
void StateStats::exit()
{

}
