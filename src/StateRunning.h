#ifndef STATERUNNING_H
#define STATERUNNING_H

using namespace std;

#include <iostream>
#include "State.h"
#include "Game.h"

/*
 * StateStart
 * Hlavni menu
 */
class StateRunning : public State
{
    public:
        StateRunning(Game &g);
        virtual ~StateRunning();

        virtual void draw();
        virtual void update();
        virtual void handleInput(char c);
        virtual void enter();
        virtual void exit();

   private:

};

#endif
