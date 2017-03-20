#include "SelectableBlock.hpp"

SelectableBlock::SelectableBlock(std::string texture_name , float x , float y)
: Block(texture_name , x , y ) { }

SelectableBlock::SelectableBlock(BlockType type , float x , float y )
: Block(type , x , y ) { }

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