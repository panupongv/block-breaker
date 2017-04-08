#pragma once

#include "TemplateData.hpp"
#include <iostream>
#include <vector>
#include <string>


class BlockData : public TemplateData
{
public:
    BlockData();
    BlockData(std::string raw);
    BlockData(BlockType type , sf::Color color , sf::Vector2i startGrid , std::vector<sf::Vector2i> movement );
    BlockData(TemplateData templateData , sf::Vector2i startGrid , std::vector<sf::Vector2i> movement );
    
    sf::Vector2i getStartGrid() const;
    const std::vector<sf::Vector2i>& getMovement() const;
    void setStartGrid( int x , int y );
    void setStartGrid( sf::Vector2i startGrid );
    void setMovement ( std::vector<sf::Vector2i> movement );

	friend std::ostream& operator<< (std::ostream& strm, const BlockData& blockData);
    
private:
    sf::Vector2i startGrid;
    std::vector<sf::Vector2i> movement;
};

