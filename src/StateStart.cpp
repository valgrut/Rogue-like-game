#include "StateStart.h"

/*
 * Constructor
 */
StateStart::StateStart(Game &g) : State(g)
{
     _stateName = "Start";
}

/*
 * Destructor
 */
StateStart::~StateStart()
{

}

/*
 *
 */
void StateStart::draw()
{
     cout << endl;
     cout << endl;
     cout << "=====================0===============" << endl;
     cout << "===0=============================" << endl;
     cout << "==========O====O===================" << endl;
     cout << "        ||                  ||     " << endl;
     cout << "        ||                  ||     " << endl;
     cout << "        ||                  ||     " << endl;
     cout << "        ||                  ||     " << endl;
     cout << "    OOOOOOOOOOOOOOOOOOOOOOOO0OOOOO" << endl;
     cout << "    O                            O" << endl;
     cout << "    0  Vítej ve Slayer's dagger  0" << endl;
     cout << "    0    1) Nová hra             0" << endl;
     cout << "    0    2) Load Game            0" << endl;
     cout << "    0    3) Delete Game          0" << endl;
     cout << "    0    4) Help                 0" << endl;
     cout << "    0    9) Exit                 0" << endl;
     cout << "    O                            O" << endl;
     cout << "    OOOOOOOOOOOOOOOOOOOOOOOO0OOOOO" << endl;
}

/*
 *
 */
void StateStart::update()
{

}

/*
 *
 */
void StateStart::handleInput(char c)
{
     switch(c)
     {
          case '1':
               _game.setState("Running");
               //game.setState("NovaHra");
               break;
          case '2':
               _game.setState("LoadGame");
               break;
          case '3':
               _game.setState("DeleteGame");
               break;
          case '4':
               _game.setState("Help");
               break;
               /*
          case '9':
               cout << endl;
               //return;
               break;
               */
     }
}

/*
 *
 */
void StateStart::enter()
{

}

/*
 *
 */
void StateStart::exit()
{

}
