#pragma once
#include "sfml.hpp"

//enum MapAlgorithm { Heat };

class ColorMapper
{
public:
    ColorMapper();
    
    sf::Color getColorFromRatio( float ratio ) const;
    sf::Color getColorFromId( int id , int num ) const;
    //    MapAlgorithm getMapAlgorithm() const;
    
//    void setMapAlgorithm( MapAlgorithm algo );
//    
//private:
//    MapAlgorithm algo = Heat;
};
