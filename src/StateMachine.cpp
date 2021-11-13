#include "StateMachine.h"

/*
 * Constructor
 */
StateMachine::StateMachine(Game &g)
{
     _states["Start"]     = new StateStart(g);
     _states["Pause"]     = new StatePause(g);
     _states["Running"]   = new StateRunning(g);
     _states["Inventory"] = new StateInventory(g);
     _states["Stats"]     = new StateStats(g);
     _states["Empty"]     = new StateEmpty(g);
     _current = _states["Start"];
}

/*
 * Destructor
 */
StateMachine::~StateMachine()
{
     clear();
     cerr << "StateMachine smazan" << endl;
}

/*
 * Vrati referenci na aktualni stav
 */
State* StateMachine::current()
{
     return _current;
}

/*
 * Prida novy stav do hash. tabulky
 */
void StateMachine::add(string s, State *state)
{
     _states[s] = state;
}

/*
 * Odstrani stav z tabulky
 */
void StateMachine::remove(string s)
{
     delete _states[s];
}

/*
 * Odstrani vsechny stavy z tabulky
 */
void StateMachine::clear()
{
     for(auto &iState : this->_states) delete iState.second;
}

/*
 * Zmeni aktualni stav na stav s
 */
void StateMachine::change(string s)
{
     if(_states.find(s) == _states.end())
     {
          cerr << "State " << s << " nebyl nalezen" << endl;
          _current = _states["Empty"];
     }
     else
     {
          _current = _states[s];
     }
}

/*
 * Na zaklade aktualniho stavu bude obstaravat vstup
 */
void StateMachine::handleInput(char c)
{
     _current->handleInput(c);
}
