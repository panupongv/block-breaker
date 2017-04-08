#include "TemplateBlock.hpp"

using namespace std;
using namespace sf;

TemplateBlock::TemplateBlock(BlockType type , sf::Color color , float x , float y)
: Block( type , x , y ) , data(TemplateData(type,color)) { }

void TemplateBlock::update()//Game& game
{
}

BlockType TemplateBlock::getType()
{
    return this->data.getType();
}

sf::Color TemplateBlock::getColor()
{
    return this->data.getColor();
}

void TemplateBlock::setType(BlockType type)
{
    this->data.setType(type);
}

void TemplateBlock::setColor(Color color)
{
    this->data.setColor(color);
}
