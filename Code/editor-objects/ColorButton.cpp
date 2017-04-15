#include "ColorButton.hpp"
#include "ColorMapper.hpp"
#include <iostream>

using namespace std;

ColorButton::ColorButton( string name , RenderLayer layer , int id , int max )
: SpriteObject(name , layer , "color-button.png" , 200 , 1 )
{
    this->id = id;
    int max_heat = max*2/3;
    int max_grey = max-max_heat;
    
    sf::Color color;
    
    if( id < max_heat )
        color = ColorMapper().getColorFromId(id, max_heat);
    else
        color = ColorMapper().getColorFromId(id-max_heat, max_grey,Grey);
    
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
