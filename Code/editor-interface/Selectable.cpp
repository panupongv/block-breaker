/*
    interface/Selectable.cpp
*/

#include "Selectable.hpp"
#include <iostream>

using namespace std;

Selectable::Selectable() {}

bool Selectable::isSelected() const
{
    return this->selected;
}

void Selectable::select()
{
    if(selected == false)
        this->onSelected();
}

void Selectable::deselect()
{
    if(selected == true)
        this->onDeselected();
}

void Selectable::onSelected()
{
    selected = true;
}

void Selectable::onDeselected()
{
    selected = false;
}
