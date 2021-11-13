#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include <map>
#include <fstream>
#include <iostream>
#include "Map.h"

//using namespace std;

/*
 * Map manager slouzi jako container pro mapy, ktere v sobe uchovava nahrane.
 * Po zavolani urcite funkce vrati urcitou mapu, aby s ni bylo mozno pracovat.
 */

class MapManager
{
    public:
        MapManager();
        virtual ~MapManager();
        Map* getMap(std::string m);

    protected:

    private:
        std::map<string, Map*> m_maps;

        bool loadMap(std::string m);

};

#endif // MAPMANAGER_H
