#pragma once

#ifdef __APPLE__
    #include <SFML/Graphics.hpp>
#else
    #include <SFML\Graphics.hpp>
#endif

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum BlockType { normal , breakable , item };

class BlockData
{
public:
    BlockData(string raw);
    BlockData(BlockType type , sf::Color color , sf::Vector2i startGrid , vector<sf::Vector2i> movement );
    BlockType getType() const;
	sf::Color getColor() const;
	sf::Vector2i getStartGrid() const;
    const vector<sf::Vector2i>& getMovement() const;
    
private:
    BlockType type;
	sf::Color color;
	sf::Vector2i startGrid;
    vector<sf::Vector2i> movement;
};

ostream& operator<< ( ostream& strm , const BlockData& blockData );