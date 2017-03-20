#include "SelectableBlock.hpp"

bool SelectableBlock::isSelected()
{
    return this->selected;
}

bool SelectableBlock::isInteractable()
{
    return this->interactable;
}

void SelectableBlock::select()
{
    this->selected = true;
    this->onSelected();
}

void SelectableBlock::deselect()
{
    this->selected = false;
    this->onDeselected();
}

void SelectableBlock::enable()
{
    this->interactable = true;
    this->onEnabled();
}

void SelectableBlock::disable()
{
    this->interactable = false;
    this->onDiabled();
}