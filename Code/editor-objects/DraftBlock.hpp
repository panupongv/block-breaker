/*
 editor-objects/DraftBlock.hpp
*/

#pragma once

#include "sfml.hpp"
#include "SpriteObject.hpp"
#include "BlockData.hpp"

class DraftBlock:
public SpriteObject,
public TemplateData
{
public:
    DraftBlock( BlockType type , sf::Color color , sf::RenderWindow& window );
    
    //getter setter
    void setAvailability(bool available);
    bool getAvailability() const;
    void hide();
    void show();
    bool isHidden();

    //overwrite
    virtual void setColor( sf::Color color );
    
    //polymorphysm
    virtual void update( EventHandler& e );
    virtual void draw( sf::RenderTarget& target );
    
private: 
    const float transparency = 0.7;
    bool available = true;
    sf::RenderWindow* window;
    
    void followCursor();
    void snapToGrid();
};
