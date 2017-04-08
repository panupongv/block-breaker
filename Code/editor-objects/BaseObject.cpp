#include "BaseObject.hpp"

using namespace std;
using namespace sf;

BaseObject::BaseObject(string name, RenderLayer layer)
{
    this->name = name;
    this->layer = layer;
}

string BaseObject::getName() const
{
    return this->name;
}

RenderLayer BaseObject::getLayer() const
{
    return this->layer;
}

void BaseObject::setLayer(RenderLayer layer)
{
    this->layer = layer;
}
