#ifndef STATESTART_H
#define STATESTART_H

using namespace std;

#include <iostream>
#include "State.h"
#include "Game.h"

/*
 * StateStart
 * Hlavni menu
 */
class StateStart : public State
{
    public:
        StateStart(Game &g);
        virtual ~StateStart();

        virtual void draw() override;
        virtual void update();
        virtual void handleInput(char c);
        virtual void enter();
        virtual void exit();

   private:

};

#endif
