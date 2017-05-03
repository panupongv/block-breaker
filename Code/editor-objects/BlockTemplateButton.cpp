#include "BlockTemplateButton.hpp"
#include <iostream>

using namespace std;

BlockTemplateButton::BlockTemplateButton( string name , RenderLayer layer , BlockType type )
:TemplateData(type , sf::Color::White)
,SpriteObject(name , layer , texture_name_of(type) )
{ }

void BlockTemplateButton::setPosition(float x, float y)
{
    SpriteObject::setPosition(x, y);
    normal_x = x;
    normal_y = y;
}

void BlockTemplateButton::setColor(sf::Color color)
{
    TemplateData::setColor(color);
    SpriteObject::setColor(color);
}
void BlockTemplateButton::update(EventHandler &e)
{
    SpriteObject::update(e);
    
    if(e.cursorOn(this))
        SpriteObject::setPosition(normal_x+selected_shift, normal_y);
    else
        SpriteObject::setPosition(normal_x, normal_y);
        
    if(isSelected())
        SpriteObject::setPosition(normal_x-selected_shift, normal_y);
}

string BlockTemplateButton::texture_name_of(BlockType type) const
{
    switch (type) {
        case normal:
            return "normal-block-button.png";
            
        case breakable:
            return "breakable-block-button.png";
            
        case item:
            return "item-block-button.png";
            
        default:
            return "no support texture";
    }
}
