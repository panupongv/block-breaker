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
    enum BlockType { normal , breakable , item };
    
public:
    BlockData(string raw);
    BlockData(BlockType type , Color color , Vector2i startGrid , vector<Vector2i> movement );
    BlockType getType() const;
    Color getColor() const;
    Vector2i getStartGrid() const;
    const vector<Vector2i>& getMovement() const;
    friend ostream& operator<< ( ostream& strm , BlockData& blockData );
    
private:
    BlockType type;
    Color color;
    Vector2i startGrid;
    vector<Vector2i> movement;
};