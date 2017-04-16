#include "EditingBlock.hpp"
#include "ResourcePath.hpp"
#include "helperfunc.hpp"

using namespace std;

EditingBlock::EditingBlock( TemplateData template_data , sf::Vector2i grid_pos , sf::Vector2i movement , Scene& scene)
: SpriteObject( "editing block" ,  RenderLayer::EditingSpaceElementLayer , texture_name_of_type(template_data.getType()) )
,BlockData( template_data.getType() , template_data.getColor() , grid_pos , movement )
,scene(scene)
{
    int grid_x = grid_pos.x;
    int grid_y = grid_pos.y;
    float pos_x = helper::pos_x_of_grid(grid_x);
    float pos_y = helper::pos_y_of_grid(grid_y);
    
    setColor(template_data.getColor());
    setPosition(pos_x, pos_y);
    
    scene.addObject(&aura);
    scene.addObject(&pin);
    
    aura.disable();
    pin.disable();
}

EditingBlock::EditingBlock ( BlockData block_data , Scene& scene)
: EditingBlock( block_data , block_data.getStartGrid() , block_data.getMovement_single() , scene ) { }

EditingBlock::~EditingBlock()
{
    scene.removeObject(&aura , false);
    scene.removeObject(&pin , false);
}

const sf::Color EditingBlock::getColor() const
{
    return TemplateData::getColor();
}

void EditingBlock::setColor(sf::Color color)
{
    TemplateData::setColor(color);
    SpriteObject::setColor(color);
}

void EditingBlock::update(EventHandler &e)
{
    sf::Vector2f block_position = getPosition();
    aura.update_position(block_position);
    
    sf::Vector2i block_grid = getStartGrid();
    sf::Vector2i movement_grid = getMovement_single();
    pin.update_grid( block_grid , movement_grid );
}

void EditingBlock::onSelected()
{
    Selectable::onSelected();
    aura.enable();
    pin.enable();
}

void EditingBlock::onDeselected()
{
    Selectable::onDeselected();
    aura.disable();
    pin.disable();
}
