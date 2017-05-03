/*
 data-class/TemplateData.cpp
*/

#include "TemplateData.hpp"

using namespace sf;

TemplateData::TemplateData(BlockType type , Color color )
: type(type) , color(color) { }

TemplateData::TemplateData() { }

BlockType TemplateData::getType() const
{
    return this->type;
}

Color TemplateData::getColor() const
{
    return this->color;
}

void TemplateData::setColor( Color color )
{
    this->color = color;
}

void TemplateData::setType( BlockType type )
{
    this->type = type;
}
