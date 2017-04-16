#pragma once
#include "SpriteObject.hpp"

class Pin : public SpriteObject
{
public:
    Pin();
    void update_grid( sf::Vector2i& grid );
    
private:
    const float levitate_speed = 1;
    
};
