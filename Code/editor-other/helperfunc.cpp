#include "helperfunc.hpp"

namespace helper
{
    sf::Vector2f getCenterOf(sf::FloatRect rect)
    {
        float mid_x = rect.left + rect.width/2;
        float mid_y = rect.top + rect.height/2;
        
        return sf::Vector2f(mid_x,mid_y);
    }

    int grid_x_of_pos ( float x )
    {
        return (int)(x/block_size_x);
    }

    int grid_y_of_pos ( float y )
    {
        return (int)(y/block_size_y);
    }

    float pos_x_of_grid ( int x )
    {
        return x*block_size_x;
    }

    float pos_y_of_grid ( int y )
    {
        return y*block_size_y;
    }

    sf::Vector2i grid_of_pos( sf::Vector2f pos )
    {
        int x = grid_x_of_pos(pos.x);
        int y = grid_y_of_pos(pos.y);
        return sf::Vector2i(x,y);
    }
    sf::Vector2f pos_of_grid( sf::Vector2i grid )
    {
        float x = pos_x_of_grid(grid.x);
        float y = pos_y_of_grid(grid.y);
        return sf::Vector2f(x,y);
    }
    
    sf::Vector2i direction_of_key( sf::Keyboard::Key key)
    {
        bool left = key == sf::Keyboard::Left;
        bool a = key == sf::Keyboard::A;
        bool right = key == sf::Keyboard::Right;
        bool d = key == sf::Keyboard::D;
        bool up = key == sf::Keyboard::Up;
        bool w = key == sf::Keyboard::W;
        bool down = key == sf::Keyboard::Down;
        bool s = key == sf::Keyboard::S;
        
        if(left || a )
            return sf::Vector2i(-1,0);
        
        if (right || d)
            return sf::Vector2i(1,0);
        
        if( up || w)
            return sf::Vector2i(0,-1);
        
        if(down || s )
            return sf::Vector2i(0,1);
        
        return sf::Vector2i(0,0);
    }
}
