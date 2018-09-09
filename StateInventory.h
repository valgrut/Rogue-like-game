#ifndef STATEINVENTORY_H
#define STATEINVENTORY_H

using namespace std;

#include <iostream>
#include "State.h"
#include "Game.h"

/*
 * StateStart
 * Hlavni menu
 */
class StateInventory : public State
{
    public:
        StateInventory(Game &g);
        virtual ~StateInventory();

        virtual void draw();
        virtual void update();
        virtual void handleInput(char c);
        virtual void enter();
        virtual void exit();

   private:

};

#endif
