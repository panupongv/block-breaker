#include "TemplateBlock.hpp"

TemplateBlock::TemplateBlock(BlockType type , sf::Color color , float x , float y)
: SelectableBlock( type , x , y )
{
    this->type = type;
    this->color = color;
}

void TemplateBlock::update()//Game& game
{
}

BlockType TemplateBlock::getType()
{
    return this->type;
}

sf::Color TemplateBlock::getColor()
{
    return this->color;
}