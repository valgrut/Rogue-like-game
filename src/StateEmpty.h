#ifndef STATEEMPTY_H
#define STATEEMPTY_H

using namespace std;

#include <iostream>
#include "State.h"
#include "Game.h"

/*
 * StateStart
 * Hlavni menu
 */
class StateEmpty : public State
{
    public:
        StateEmpty(Game &g);
        virtual ~StateEmpty();

        virtual void draw();
        virtual void update();
        virtual void handleInput(char c);
        virtual void enter();
        virtual void exit();

   private:

};

#endif
