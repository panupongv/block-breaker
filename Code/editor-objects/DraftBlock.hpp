#pragma once

#include "SpriteObject.hpp"
#include "BlockData.hpp"

class DraftBlock: public SpriteObject
{
public:
    DraftBlock();
    DraftBlock( std::string textureName , sf::RenderWindow &window , sf::Color color = sf::Color::White );
    
    //getter setter
    void setAvailability(bool available);
    bool getAvailability() const;

    //overwrite
    virtual void setColor( sf::Color color );
    
    //polymorphysm
    virtual void update( EventHandler& e );
    virtual void draw( sf::RenderWindow& window );
    
private: 
    const float transparency = 0.5;
    bool available = true;
    sf::RenderWindow* window;
    
    void followCursor();
    void snapToGrid();
};
