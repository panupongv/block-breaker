/*
 base/BaseObject.cpp
*/

#include "BaseObject.hpp"

using namespace std;
using namespace sf;

BaseObject::BaseObject(string name, RenderLayer layer)
{
    this->name = name;
    this->layer = layer;
}

BaseObject::~BaseObject()
{
    
}

string BaseObject::getName() const
{
    return this->name;
}

RenderLayer BaseObject::getLayer() const
{
    return this->layer;
}

bool BaseObject::isActive() const
{
    return this->active;
}

void BaseObject::setLayer(RenderLayer layer)
{
    this->layer = layer;
}

void BaseObject::enable()
{
    this->active = true;
}

void BaseObject::disable()
{
    this->active = false;
}
