#include "Cell.h"

Cell::Cell() : m_tile('.'), m_tileName("Floor")
{
}

Cell::Cell(char t) : m_tile(t)
{
     switch(t)
     {

          case '?':
               m_tileName = "Loot";
               break;

          case '$':
               m_tileName = "Gold";
               break;

          case '@':
               m_tileName = "Player";
               break;

          case 't':
               m_tileName = "Teleport";
               //tile = new Teleport();
               break;

          case '+':
               m_tileName = "Door";
               //tile = new Downstairs();
               break;

          case '.':
               m_tileName = "Floor";
               //tile = new Downstairs();
               break;

          case '>':
               m_tileName = "Downstairs";
               //tile = new Downstairs();
               break;

          case '<':
               m_tileName = "Upstairs";
               //tile = new Upstairs();
               break;

          case '#':
               m_tileName = "Wall";
               //tile = new Wall();
               break;

          case '~':
               m_tileName = "Water";
               //tile = new Watter();
               break;
     }
}

Cell::~Cell()
{
    //dtor
}

char Cell::cell() const
{
    return this->m_tile;
}

void Cell::setCell(char t)
{
    this->m_tile = t;
    switch(t)
    {
         case '.':
              m_tileName = "Floor";
              //tile = new Downstairs();
              break;

         case '>':
              m_tileName = "Downstairs";
              //tile = new Downstairs();
              break;

         case '<':
              m_tileName = "Upstairs";
              //tile = new Upstairs();
              break;

         case '#':
              m_tileName = "Wall";
              //tile = new Wall();
              break;

         case '~':
              m_tileName = "Water";
              //tile = new Watter();
              break;
    }
}

string Cell::cellName() const
{
     return this->m_tileName;
}
