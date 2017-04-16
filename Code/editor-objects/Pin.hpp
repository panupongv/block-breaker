#pragma once
#include "SpriteObject.hpp"

class Pin : public SpriteObject
{
public:
    Pin();
    void update_grid( sf::Vector2i block_grid , sf::Vector2i move_grid );
    
private:
    void set_no_direction();
    void set_horizontal();
    void set_vertical();
    
private:
    const float levitate_speed = 1;
    
};
