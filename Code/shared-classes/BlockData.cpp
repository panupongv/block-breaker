/*
 data-class/BlockData.cpp
*/

#include "BlockData.hpp"
#include "CSVSplitter.hpp"

using namespace std;

BlockData::BlockData() {} 
BlockData::BlockData ( string raw )
{
    CSVSplitter splitter(raw);
    vector<string> splitted = splitter.getResult();
    
    BlockType type = (BlockType)atoi(splitted[0].c_str());
    
    sf::Color color = sf::Color(
        atoi(splitted[1].c_str()),
        atoi(splitted[2].c_str()),
        atoi(splitted[3].c_str())
    );
    
    sf::Vector2i startGrid = sf::Vector2i(
        atoi(splitted[4].c_str()),
        atoi(splitted[5].c_str())
    );
    
    vector<sf::Vector2i> movement;
    for(int i = 6 ; i+1 < splitted.size() ; i += 2)
    {
        movement.push_back(
           sf::Vector2i(
                atoi(splitted[i].c_str()),
                atoi(splitted[i+1].c_str())
            )
        );
    }
    
    movement.push_back(startGrid);
    movement.push_back(startGrid);
    
    *this = BlockData::BlockData( type , color , startGrid , movement[1] );
}

BlockData::BlockData ( BlockType type , sf::Color color , sf::Vector2i startGrid , sf::Vector2i movement )
:TemplateData(type , color)
{
    this->startGrid = startGrid;
    setMovement(movement);
}

sf::Vector2i BlockData::getStartGrid() const
{
    return this->startGrid;
}

const sf::Vector2i BlockData::getMovement_single() const
{
    if(movement.size() < 2)
        return getStartGrid();
    else
        return movement[1];
}
const vector<sf::Vector2i>& BlockData::getMovement() const
{
    return this->movement;
}

void BlockData::setStartGrid( int x, int y)
{
    this->setStartGrid( sf::Vector2i(x,y) );
}

void BlockData::setStartGrid( sf::Vector2i _start )
{
    this->startGrid = _start;
}

void BlockData::setMovement( sf::Vector2i movement )
{
    cancelMovement();
    this->movement.push_back(getStartGrid());
    this->movement.push_back(movement);
}

void BlockData::cancelMovement()
{
    this->movement.clear();
}

ostream& operator<< ( ostream& strm , const BlockData& blockData )
{
    sf::Color blockColor = blockData.getColor();
    sf::Vector2i blockStartGrid = blockData.getStartGrid();
    vector<sf::Vector2i> blockMovement = blockData.getMovement();
    
    strm    << blockData.getType() << ","
            << (int)blockColor.r << ","
            << (int)blockColor.g << ","
            << (int)blockColor.b << ","
            << blockStartGrid.x << ","
            << blockStartGrid.y ;
    
    for(int i = 0 ; i < blockMovement.size() ; ++i)
    {
        strm << "," << blockMovement[i].x << "," << blockMovement[i].y;
    }
    
    return strm;
}
