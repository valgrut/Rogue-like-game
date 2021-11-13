#ifndef CELL_H
#define CELL_H

#include <string>
#include <iostream>

using namespace std;

class Cell
{
    public:
        Cell();
        Cell(char t);
        virtual ~Cell();
        char cell() const;
        void setCell(char t);
        string cellName() const;

        friend ostream &operator<<( ostream &output, const Cell &c )
        {
             output << c.m_tile;
             return output;
        }


    protected:

    private:
        char m_tile;
        string m_tileName;
        //MapObject tile;
};

#endif // CELL_H
