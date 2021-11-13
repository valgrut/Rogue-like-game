#include "Map.h"

Map::Map() : _name("None")
{
     m_mapSize.first = 0;
     m_mapSize.second = 0;
}

Map::Map(std::string name, std::pair<int, int> size, ifstream &in ) : _name(name), m_mapSize(size)
{
     char c;
     m_map.resize(size.second);

     for(int y = 0; y < size.second; y++)
     {
          m_map.at(y).resize(size.first);

          for(int x = 0; x < size.first; x++)
          {
               //std::cout << y << " " << x << std::endl;

               if(!in.get(c))
               {
                    std::cerr << "konec vstupu" << std::endl;
                    break;
                    //return;
               }
               Cell newCell(c);
               m_map.at(y).at(x) = newCell;
          }
     }
}

Item & Map::itemAt(int x, int y)
{
     std::pair<int,int> p(x,y);
     return _itemsOnMap[p];
}

void Map::placeItemTo(unsigned int x, unsigned int y, char c, Item &it)
{
     std::pair<int,int> coord(x,y);
     m_map.at(y).at(x) = Cell(c);
     _itemsOnMap[coord] = it;
}

void Map::takeItemFrom(unsigned int x, unsigned int y, Cell &_tmp)
{
     std::pair<int,int> coord(x,y);
     //if(_itemsOnMap[coord])
     //{
          _tmp = Cell('.');
          //_itemsOnMap[coord].erase();

          //TODO dodelat
     //}
}

void Map::draw2(int px, int py, int v)
{
     //std::cerr << "Vykresluji mapu: " << mapName() << std::endl;

     int dolx = 0;
     int doly = 0;
     int horx = m_mapSize.first;
     int hory = m_mapSize.second;

     if(py - v <= 0)
          doly = 0;
     else
          doly = py - v;

     if(px - v <= 0)
          dolx = 0;
     else
          dolx = px - v;

     if(py + v >= m_mapSize.second)
          hory = m_mapSize.second;
     else
          hory = py + v;

     if(px + v >= m_mapSize.first)
          horx = m_mapSize.first-1;
     else
          horx = px + v;

     for(int y = doly; y < hory; y++)
     {
          for(int x = dolx; x < horx; x++)
          {
               std::cout << m_map.at(y).at(x).cell();
          }

          std::cout << std::endl;
     }
     std::cout << std::endl;

     //std::cerr << "Mapa je vykreslena" << std::endl;
}

void Map::draw()
{
     //std::cerr << "Vykresluji mapu: " << mapName() << std::endl;

     for(int y = 0; y < m_mapSize.second; y++)
     {
          for(int x = 0; x < m_mapSize.first; x++)
          {
               std::cout << m_map.at(y).at(x).cell();
          }

          //std::cout << std::endl;
     }
     //std::cerr << "Mapa je vykreslena" << std::endl;
}

std::string Map::mapName() const
{
     return this->_name;
}

Cell& Map::cellAt(int x, int y)
{
     return m_map.at(y).at(x);
}

void Map::setCellAt(int x, int y, Cell c)
{
     m_map.at(y).at(x) = c;
}

Map::~Map()
{
     std::cerr << "Mapa " << _name << " znicena." << std::endl;
}
