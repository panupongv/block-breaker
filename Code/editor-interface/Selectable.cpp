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
    this->onSelected();
}

void Selectable::deselect()
{
    this->onDeselected();
}
