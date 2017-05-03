/*
 editor-objects/Pin.cpp
*/

#include "Pin.hpp"
#include "helperfunc.hpp"

using namespace std;

Pin::Pin()
:SpriteObject("pin", RenderLayer::EditingSpacePinLayer , "pin.png" , 14,14)
{}

void Pin::update_grid( sf::Vector2i block_grid , sf::Vector2i move_grid  )
{
    if(block_grid == move_grid)
        set_no_direction();
    else if(block_grid.y == move_grid.y)
        set_horizontal();
    else if(block_grid.x == move_grid.x)
        set_vertical();
    
    sf::Vector2f grid_pos = helper::pos_of_grid(move_grid);
    grid_pos.x += helper::block_size_x/2;
    grid_pos.y += helper::block_size_y/2;
    
    setPosition(grid_pos.x, grid_pos.y , Center);
}

void Pin::set_no_direction()
{
    setFrame(0);
}

void Pin::set_horizontal()
{
    setFrame(1);
}

void Pin::set_vertical()
{
    setFrame(2);
}
