#ifndef STATE_H
#define STATE_H

using namespace std;

#include <iostream>
#include <string>
#include "iState.h"

// forward declaration
class Game;

/*
 * State
 * Reprezentace State, slouzi jako base pro konkretni States
 */
class State : public iState
{
    public:
        State(Game &g);
        State(const State& src);
        virtual ~State();

        virtual void draw() = 0;
        virtual void update();
        virtual void handleInput(char c);
        virtual void enter();
        virtual void exit();
        virtual string stateName() const {return this->_stateName;}

        Game & _game;
   protected:
        string _stateName;
};

#endif // MAPMANAGER_H
