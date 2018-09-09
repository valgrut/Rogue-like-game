#include "MapManager.h"

MapManager::MapManager()
{
    //ctor
}

MapManager::~MapManager()
{
     for(auto &i : m_maps) delete i.second;

     std::cerr << "ManManager znicen" << std::endl;
}

Map* MapManager::getMap(std::string mapName)
{
     if(m_maps.find(mapName) == m_maps.end())
     {
          std::cerr << "Mapa " << mapName << " nebyla nalezena v poli map" << std::endl;

          //zkusime mapu nacist
          bool opening = loadMap(mapName);
          if(opening)
          {
               std::cerr << "Mapa " << mapName << " byla vlozena do pole" << std::endl;
               return m_maps.at(mapName);
          }
          else
          {
               std::cerr << "Mapa " << mapName << " nebyla nalezena" << std::endl;
               return NULL;
          }
     }
     else
     {
          std::cerr << "Mapa " << mapName << " byla nalezena" << std::endl;
          return m_maps.at(mapName);
     }
}

bool MapManager::loadMap(std::string mapName)
{
     ifstream inFile;
     inFile.open("maps/"+mapName);

     if(inFile.is_open())
          std::cerr << "Soubor se otevrel" << std::endl;
     else
     {
          std::cerr << "Nepodarilo se otevrit soubor s mapou " << mapName << std::endl;
          return false;
     }

     // velikost mapy
     std::pair<int, int> mapSize;
     inFile >> mapSize.first;
     inFile >> mapSize.second;

     // zbavime se konce radku
     char c;
     inFile.get(c);

     //std::cerr << mapSize.first;
     //std::cerr << mapSize.second;

     // kvuli '\n' musime upravit rozmer mapy
     mapSize.first += 1;

     // velikost mapy asociujeme k prislusne mape
     //m_mapSize.insert(pair<std::string, pair<int,int> >(mapName, mapSize));

     // vytvorime novou mapu a nahrajeme ji do asociativniho pole
     Map *newMap = new Map(mapName, mapSize, inFile);
     m_maps.insert(std::pair<std::string, Map*>(mapName, newMap));

     // zavreme soubor
     inFile.close();
     return true;
}
