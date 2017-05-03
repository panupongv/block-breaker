/*
 WindowHelper.hpp
*/

#pragma once

#include "sfml.hpp"

class WindowHelper
{
public:
    static const int res_x = 800;
    static const int res_y = 600;
    static const int default_size_x = 1600;
    static const int default_size_y = 1200;
    
    static sf::Vector2f getMousePosition( sf::RenderWindow& window );
    static sf::RenderWindow& createWindow( );
    static void resizeWindow(sf::RenderWindow& window, int x , int y );
};
