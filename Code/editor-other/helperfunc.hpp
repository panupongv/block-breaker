#pragma once
#include "sfml.hpp"

namespace helper
{
    const int block_size_x = 50;
    const int block_size_y = 18;
    const int grid_num_x = 12;
    const int grid_num_y = 32;

    sf::Vector2f getCenterOf(sf::FloatRect rect);

    int grid_x_of_pos( float x );
    int grid_y_of_pos( float y );
    float pos_x_of_grid( int x );
    float pos_y_of_grid( int y );
    sf::Vector2i grid_of_pos( sf::Vector2f pos );
    sf::Vector2f pos_of_grid( sf::Vector2i grid );
    sf::Vector2i direction_of_key ( sf::Keyboard::Key key );
}
