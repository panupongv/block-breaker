#include "EditableBlock.hpp"

using namespace std;
using namespace sf;

EditableBlock::EditableBlock( BlockData data )
: Block(data) , SnappableObject(block_size_x , block_size_y) {
    this->data = data;
}

EditableBlock::EditableBlock( TemplateData data , int grid_x , int grid_y )
: EditableBlock(data.getType(),data.getColor(),grid_x , grid_y) { }

EditableBlock::EditableBlock( TemplateData data , float x , float y )
: EditableBlock(data.getType() , data.getColor() , x , y ) { }

EditableBlock::EditableBlock( BlockType type , Color color , Vector2i startGrid )
: EditableBlock(type , color , startGrid.x , startGrid.y ) { }

EditableBlock::EditableBlock( BlockType type , Color color , int grid_x , int grid_y )
:Block(type  , grid_x*block_size_x , grid_y*block_size_y ) , SnappableObject(block_size_x , block_size_y) { }

EditableBlock::EditableBlock( BlockType type , Color color , float x , float y )
: Block(type , x , y ), SnappableObject(block_size_x , block_size_y)
{
    Vector2i grid = getSnapGrid(x, y);
    this->data = BlockData( type , color , grid , vector<Vector2i>() );
}

void EditableBlock::update()
{
    
}

void EditableBlock::onSelected()
{
    //TODO
}

void EditableBlock::onDeselected()
{
    //TODO
}

void EditableBlock::onEnabled()
{
    //TODO
}

void EditableBlock::onDisabled()
{
    //TODO
}

void EditableBlock::onLeftClick()
{
    //TODO
}

void EditableBlock::onRightClick()
{
    //TODO
}
