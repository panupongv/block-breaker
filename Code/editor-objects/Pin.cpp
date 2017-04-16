#include "Pin.hpp"
#include "helperfunc.hpp"

using namespace std;

Pin::Pin()
:SpriteObject("pin", RenderLayer::EditingSpacePinLayer , "pin.png")
{}

void Pin::update_grid(sf::Vector2i &grid)
{
    sf::Vector2f grid_pos = helper::pos_of_grid(grid);
    grid_pos.x += helper::block_size_x/2;
    grid_pos.y += helper::block_size_y/2;
    
    setPosition(grid_pos.x, grid_pos.y , Center);
}
