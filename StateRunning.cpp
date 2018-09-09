#include "StateRunning.h"

/*
 * Constructor
 */
StateRunning::StateRunning(Game &g) : State(g)
{
     _stateName = "Running";
}

/*
 * Destructor
 */
StateRunning::~StateRunning()
{

}

/*
 *
 */
void StateRunning::draw()
{
     _game._player->drawHp();
     _game._player->drawLevel();
     _game._player->drawGold();


     /* ----- vykresleni mapy ----- */
     cout << endl << "Map: " << _game._current->mapName() << endl;
     //_current->draw();
     _game._current->draw2(_game._player->X(), _game._player->Y(), 5);

     //cout << _tmp.cellName() << endl;
     cout << _game._tmp.cellName() << " : " << _game._current->itemAt(_game._player->X(), _game._player->Y()).itemName() << endl;
     if(_game._tmp.cell() == '?' || _game._tmp.cell() == '$')
     {
          cout << "1) pick Item" << endl;
     }

     //cout << endl << _player->X() << " " << _player->Y() << endl;

     cout << "p) Pause Game" << endl;

     // TODO DOCASNEEE
     cout << endl;
     _game._player->drawEquip();
}

/*
 *
 */
void StateRunning::update()
{

}

/*
 *
 */
void StateRunning::handleInput(char c)
{
     switch(c)
     {
          // POHYB
          case 'w':
               _game._player->move(-1, 0, _game);
               break;

          case 's':
               _game._player->move(1, 0, _game);
               break;

          case 'a':
               _game._player->move(0, -1, _game);
               break;

          case 'd':
               _game._player->move(0, 1, _game);
               break;

          /******************************************************/
          case 'i':
               if(_game._player->hp() >= 0)
                    _game._player->setHp(_game._player->hp()-1);
               break;

          case 'p':
               _game.setState("Pause");
               c = '.';
               break;

          case '9':
               _game.setState("Start");
               c = '.';
               break;

          case '>':
               if(_game._tmp.cell() == '>')
               {
                    _game.setMap("Labyrint");
               }
               break;

          // vzit predmet
          case '1':
               if(_game._tmp.cell() == '?')
               {
                    // vlozeni predmetu do inventare
                    _game._player->addItem(_game._current->itemAt(_game._player->X(), _game._player->Y()));
                    // odstraneni predmetu z policka mapy
                    _game._current->takeItemFrom(_game._player->X(), _game._player->Y(), _game._tmp);
               }
               break;

          /***** nastaveni map, POUZE PRO TEST *******/
          case '4':
               //restoreCell(game);
               _game.setMap("Base");
               break;

          case '5':
               //restoreCell(game);
               _game.setMap("Arena");
               break;

          case '6':
               //restoreCell(game);
               _game.setMap("Labyrint");
               break;

          case '7':
               //restoreCell(game);
               _game.setMap("Dungeon1");
               break;

          default:
               break;
     }
}

/*
 *
 */
void StateRunning::enter()
{

}

/*
 *
 */
void StateRunning::exit()
{

}
