#include "StatePause.h"

/*
 * Constructor
 */
StatePause::StatePause(Game &g) : State(g)
{
     _stateName = "Pause";
}

/*
 * Destructor
 */
StatePause::~StatePause()
{

}

/*
 *
 */
void StatePause::draw()
{
     cout << "    OOOOOOOOOOOOOOOOOOOOOOOO0OOOOO" << endl;
     cout << "    O                            O" << endl;
     cout << "    0     ***** PAUSED *****     0" << endl;
     cout << "    0    p) back to game         0" << endl;
     cout << "    0    1) Inventory            0" << endl;
     cout << "    0    2) Stats                0" << endl;
     cout << "    0    3) Quests               0" << endl;
     cout << "    0    4) Save Game            0" << endl;
     cout << "    0    9) Exit to Main Menu    0" << endl;
     cout << "    O                            O" << endl;
     cout << "    OOOOOOOOOOOOOOOOOOOOOOOO0OOOOO" << endl;
}

/*
 *
 */
void StatePause::update()
{

}

/*
 *
 */
void StatePause::handleInput(char c)
{
     switch(c)
     {
          case '1':
               _game.setState("Inventory");
               break;
          case '2':
               _game.setState("Stats");
               break;
          case '3':
               _game.setState("Quests");
               break;
          case '4':
               _game.setState("SaveGame");
               break;

          case '9':
               _game.setState("Start");
               c = '.';
               break;

          case 'p':
               _game.setState("Running");
               c = '.';
               break;

          default:
               break;
     }
}

/*
 *
 */
void StatePause::enter()
{

}

/*
 *
 */
void StatePause::exit()
{

}
