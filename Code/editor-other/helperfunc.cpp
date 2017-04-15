#include "helperfunc.hpp"

sf::Vector2f getCenterOf(sf::FloatRect rect)
{
    float mid_x = rect.left + rect.width/2;
    float mid_y = rect.top + rect.height/2;
    
    return sf::Vector2f(mid_x,mid_y);
}
