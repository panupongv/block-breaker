#pragma once
#include "SpriteObject.hpp"
#include "Selectable.hpp"

class ColorButton : public SpriteObject , public Selectable
{
public:
    ColorButton(std::string name , RenderLayer layer , int id , int num );
    
    virtual void setPosition( float x, float y );
    
    //polymorphism
    virtual void update(EventHandler& e);
    
private:
    int id = -1;
    float normal_x = 0;
    float normal_y = 0;
};
