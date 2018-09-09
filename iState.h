#ifndef ISTATE_H
#define ISTATE_H

using namespace std;

class iState
{
public:
     virtual void draw() = 0;
     virtual void update() = 0;
     virtual void handleInput(char c) = 0;
     virtual void enter() = 0;
     virtual void exit() = 0;
     virtual ~iState();
};

#endif
