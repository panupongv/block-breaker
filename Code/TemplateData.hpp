#pragma once

#ifdef __APPLE__
#include <SFML/Graphics.hpp>
#else
#include <SFML\Graphics.hpp>
#endif

enum BlockType { normal , breakable , item };

class TemplateData
{
public:
    TemplateData( BlockType type , sf::Color color );
    
    BlockType getType() const;
    sf::Color getColor() const;
    
protected:
    TemplateData();
    
private:
    BlockType type;
    sf::Color color;
};
