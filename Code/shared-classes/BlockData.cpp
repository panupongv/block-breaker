#include "BlockData.hpp"
//#include "shared-classes\CSVSplitter.hpp"
#include "CSVSplitter.hpp"

using namespace sf;
using namespace std;

BlockData::BlockData() {} 
BlockData::BlockData ( string raw )
{
    CSVSplitter splitter(raw);
    vector<string> splitted = splitter.getResult();
    
    BlockType type = (BlockType)atoi(splitted[0].c_str());
    
    Color color = Color(
        atoi(splitted[1].c_str()),
        atoi(splitted[2].c_str()),
        atoi(splitted[3].c_str())
    );
    
    Vector2i startGrid = Vector2i(
        atoi(splitted[4].c_str()),
        atoi(splitted[5].c_str())
    );
    
    vector<Vector2i> movement;
    for(int i = 6 ; i+1 < splitted.size() ; i += 2)
    {
        movement.push_back(
            Vector2i(
                atoi(splitted[i].c_str()),
                atoi(splitted[i+1].c_str())
            )
        );
    }
    
    *this = BlockData::BlockData( type , color , startGrid , movement );
}

BlockData::BlockData ( BlockType type , Color color , Vector2i startGrid , vector<Vector2i> movement )
:TemplateData(type , color)
{
    this->startGrid = startGrid;
    this->movement = movement;
}

Vector2i BlockData::getStartGrid() const
{
    return this->startGrid;
}

const vector<Vector2i>& BlockData::getMovement() const
{
    return this->movement;
}

void BlockData::setStartGrid( int x, int y)
{
    this->setStartGrid( Vector2i(x,y) );
}

void BlockData::setStartGrid( Vector2i _start )
{
    this->startGrid = _start;
}

void BlockData::setMovement( vector<Vector2i> movement )
{
    this->movement = movement;
}

ostream& operator<< ( ostream& strm , const BlockData& blockData )
{
    Color blockColor = blockData.getColor();
    Vector2i blockStartGrid = blockData.getStartGrid();
    vector<Vector2i> blockMovement = blockData.getMovement();
    
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