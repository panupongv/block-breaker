#include "InteractableObject.hpp"

InteractableObject::~InteractableObject() {}

bool InteractableObject::isSelected()
{
    return this->selected;
}

bool InteractableObject::isInteractable()
{
    return this->interactable;
}

void InteractableObject::select()
{
    this->selected = true;
    this->onSelected();
}

void InteractableObject::deselect()
{
    this->selected = false;
    this->onDeselected();
}

void InteractableObject::enable()
{
    this->interactable = true;
    this->onEnabled();
}

void InteractableObject::disable()
{
    this->interactable = false;
    this->onDiabled();
}