#ifndef STATEPAUSE_H
#define STATEPAUSE_H

using namespace std;

#include <iostream>
#include "State.h"
#include "Game.h"

/*
 * StateStart
 * Hlavni menu
 */
class StatePause : public State
{
    public:
        StatePause(Game &g);
        virtual ~StatePause();

        virtual void draw();
        virtual void update();
        virtual void handleInput(char c);
        virtual void enter();
        virtual void exit();

   private:

};

#endif
