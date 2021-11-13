#ifndef STATESTATS_H
#define STATESTATS_H

using namespace std;

#include <iostream>
#include "State.h"
#include "Game.h"

/*
 * StateStart
 * Hlavni menu
 */
class StateStats : public State
{
    public:
        StateStats(Game &g);
        virtual ~StateStats();

        virtual void draw();
        virtual void update();
        virtual void handleInput(char c);
        virtual void enter();
        virtual void exit();

   private:

};

#endif
