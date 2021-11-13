#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include "Cell.h"
#include "Item.h"

//using namespace std;

class Map
{
    public:
        Map();
        Map(std::string name, std::pair<int, int> size, ifstream &in);
        virtual ~Map();
        void draw();
        void draw2(int px, int py, int v);
        std::string mapName() const;
        Cell& cellAt(int x, int y);
        void setCellAt(int x, int y, Cell c);

        Item & itemAt(int x, int y);
        void placeItemTo(unsigned int x, unsigned int y, char c, Item &it);
        void takeItemFrom(unsigned int x, unsigned int y, Cell &c);
        //Item & itemAt(pair<int, int> coord);

    protected:

    private:
         std::vector< std::vector<Cell> > m_map;
         std::pair<int, int> m_mapSize;
         std::map< std::pair<int, int>, Item> _itemsOnMap;
         std::string _name;
};

#endif // MAP_H
