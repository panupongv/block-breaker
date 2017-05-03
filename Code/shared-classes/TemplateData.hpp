/*
 data-class/TemplateData.hpp
*/

#pragma once

#include "sfml.hpp"
#include "enums.hpp"

class TemplateData
{
public:
    TemplateData( BlockType type , sf::Color color );
    
    BlockType getType() const;
    sf::Color getColor() const;
    void setType( BlockType type );
    void setColor( sf::Color color );
    
protected:
    TemplateData();
    
private:
    BlockType type;
    sf::Color color;
};
