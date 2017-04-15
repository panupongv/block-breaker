#include "ColorButton.hpp"
#include "ColorMapper.hpp"
#include <iostream>

using namespace std;

ColorButton::ColorButton( string name , RenderLayer layer , int id , int max )
: SpriteObject(name , layer , "color-button.png" , 200 , 4 )
{
    this->id = id;
    
    sf::Color color = ColorMapper().getColorFromId(id, max);
    setColor(color);
}

void ColorButton::setPosition(float x, float y)
{
    y += id*getRect().height;
    
    SpriteObject::setPosition(x, y);
    
    normal_x = x;
    normal_y = y;
}

void ColorButton::update(EventHandler &e)
{
    SpriteObject::update(e);
    
    if(e.cursorOn(this))
        SpriteObject::setPosition(normal_x+10, normal_y);
    else
        SpriteObject::setPosition(normal_x, normal_y);
    
    if(isSelected())
        setFrame(1);
    else
        setFrame(0);
}
