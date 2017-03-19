#include "BlockData.hpp"
#include "CSVSPlitter.hpp"

using namespace sf;

BlockData::BlockData ( string raw )
{
    CSVSplitter splitter(raw);
    vector<string> splitted = splitter.getResult();
    
    this->type = (BlockType)atoi(splitted[0].c_str());
    
    this->color = Color(
        atoi(splitted[1].c_str()),
        atoi(splitted[2].c_str()),
        atoi(splitted[3].c_str())
    );
    
    this->startGrid = Vector2i(
        atoi(splitted[4].c_str()),
        atoi(splitted[5].c_str())
    );
    
    for(int i = 6 ; i+1 < splitted.size() ; i += 2)
    {
        this->movement.push_back(
            Vector2i(
                atoi(splitted[i].c_str()),
                atoi(splitted[i+1].c_str())
            )
        );
    }
}

BlockData::BlockData ( BlockType type , Color color , Vector2i startGrid , vector<Vector2i> movement )
{
    this->type = type;
    this->color = color;
    this->startGrid = startGrid;
    this->movement = movement;
}

BlockType BlockData::getType() const
{
    return this->type;
}

Color BlockData::getColor() const
{
    return this->color;
}

Vector2i BlockData::getStartGrid() const
{
    return this->startGrid;
}

const vector<Vector2i>& BlockData::getMovement() const
{
    return this->movement;
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