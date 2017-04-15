#include "EditingBlock.hpp"
#include "ResourcePath.hpp"
#include "helperfunc.hpp"

using namespace std;

EditingBlock::EditingBlock( TemplateData template_data , sf::Vector2i grid_pos , sf::Vector2i movement)
: SpriteObject( "editing block" ,  RenderLayer::EditingSpaceElementLayer , texture_name_of_type(template_data.getType()) )
,BlockData( template_data.getType() , template_data.getColor() , grid_pos , movement )
{
    int grid_x = grid_pos.x;
    int grid_y = grid_pos.y;
    float pos_x = helper::pos_x_of_grid(grid_x);
    float pos_y = helper::pos_y_of_grid(grid_y);
    
    setColor(template_data.getColor());
    setPosition(pos_x, pos_y);
}

EditingBlock::EditingBlock ( BlockData block_data )
: EditingBlock( block_data , block_data.getStartGrid() , block_data.getMovement_single() ) { }

const sf::Color EditingBlock::getColor() const
{
    return TemplateData::getColor();
}

void EditingBlock::setColor(sf::Color color)
{
    TemplateData::setColor(color);
    SpriteObject::setColor(color);
}
