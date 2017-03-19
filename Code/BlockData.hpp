#pragma once

#ifdef __APPLE__
    #include <SFML/Graphics.hpp>
#else
    #include <SFML\Graphics.hpp>
#endif

#include <iostream>
#include <vector>
#include <string>

using namespace sf;
using namespace std;

class BlockData
{
public:
    enum BlockType { normal , breakable , item };
    BlockData(string raw);
    BlockData(BlockType type , Color color , Vector2i startGrid , vector<Vector2i> movement );
    BlockType getType() const;
    Color getColor() const;
    Vector2i getStartGrid() const;
    const vector<Vector2i>& getMovement() const;
    
private:
    BlockType type;
    Color color;
    Vector2i startGrid;
    vector<Vector2i> movement;
};

ostream& operator<< ( ostream& strm , const BlockData& blockData );