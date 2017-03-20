#include "EditableBlock.hpp"

using namespace std;
using namespace sf;

EditableBlock::EditableBlock( TemplateBlock tb , int grid_x , int grid_y )
:TemplateBlock( tb.getType() , tb.getColor() ,  grid_x*block_size_x , grid_y*block_size_y )
{
    this->grid_x = grid_x;
    this->grid_y = grid_y;
}

void EditableBlock::update()
{
    
}