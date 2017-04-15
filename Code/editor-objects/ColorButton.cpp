#include "ColorButton.hpp"
#include <iostream>

using namespace std;

ColorButton::ColorButton( string name , RenderLayer layer , int id , int max )
: SpriteObject(name , layer , "color-button.png" , 200 , 4 )
{
    float slot = 1.0/(max-1);
    float value = slot*id;
    cout << value << endl;
    
    float red,green,blue;
    
    if(value >= 0 && value <= 0.25*0.5 )
        red = 0.5 + 4*value;
    else if(value >= 0.25*0.5 && value <= 0.25*1.5 )
        red = 1;
    else if(value >= 0.25*1.5 && value <= 0.25*2.5 )
        red = 1 - 4*(value-0.25*1.5);
    else
        red = 0;
    
    if(value >= 0.25*0.5 && value <= 0.25*1.5 )
        green = 4*(value-0.25*0.5);
    else if(value >= 0.25*1.5 && value <= 0.25*2.5 )
        green = 1;
    else if(value >= 0.25*2.5 && value <= 0.25*3.5 )
        green = 1 - 4*(value-0.25*2.5);
    else
        green = 0;
    
    if(value >= 0.5 && value <= 0.25*2.5 )
        blue = 4*(value-0.5);
    else if(value >= 0.25*2.5 && value <= 0.25*3.5 )
        blue = 1;
    else if(value >= 0.25*3.5 && value <= 1 )
        blue = 1 - 4*(value-0.25*3.5);
    else
        blue = 0;
    
//    cout << red << "-" << green << "-" << blue << endl;
    red *= 255;
    green *= 255;
    blue *= 255;
    
    setColor(sf::Color(red,green,blue));
    this->id = id;
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
