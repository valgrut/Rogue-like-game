#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <map>
#include <iostream>

#include "Game.h" // nemusi byt, proc?

#include "State.h"
#include "StateStart.h"
#include "StatePause.h"
#include "StateRunning.h"
#include "StateInventory.h"
#include "StateEmpty.h"
#include "StateStats.h"

using namespace std;

class Game; // nemusi byt, proc?

/*
 * StateMachine
 * Trida bude spravovat aktualni stav hry.
 */
class StateMachine
{
    public:
        StateMachine(Game &g);
        virtual ~StateMachine();

        State* current();
        void add(string s, State *state);
        void remove(string s);
        void clear();
        void change(string s);
        void handleInput(char c);

    protected:

    private:
        map<string, State*> _states;
        State *_current;
};

#endif
