#pragma once
#include "sfml.hpp"

enum MapAlgorithm { Heat , Grey };

class ColorMapper
{
public:
    ColorMapper();
    
    sf::Color getColorFromRatio( float ratio , MapAlgorithm algo = Heat) const;
    sf::Color getColorFromId( int id , int num , MapAlgorithm algo = Heat) const;
    
    
private:
    sf::Color heat_color_of( float ratio ) const;
    sf::Color grey_color_of( float ratio ) const;
};
