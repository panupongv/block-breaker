#pragma once

#ifdef __APPLE__
#include <SFML/Graphics.hpp>
#else
#include <SFML\Graphics.hpp>
#endif

class SnappableObject
{
protected :
    SnappableObject( int size_x , int size_y ) ;

public:
    virtual ~SnappableObject() = 0;
    sf::Vector2i getSnapGrid( float x , float y );
    sf::Vector2f getSnapPosition( float x , float y );
    sf::Vector2f getSnapPosition( int grid_x , int grid_y );
    
private:
    int grid_size_x;
    int grid_size_y;
};