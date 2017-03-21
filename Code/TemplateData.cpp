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