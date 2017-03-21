#include "InteractableBlock.hpp"

InteractableBlock::InteractableBlock(std::string texture_name , float x , float y)
: Block(texture_name , x , y ) { }

InteractableBlock::InteractableBlock(BlockType type , float x , float y )
: Block(type , x , y ) { }

bool InteractableBlock::isSelected()
{
    return this->selected;
}

bool InteractableBlock::isInteractable()
{
    return this->interactable;
}

void InteractableBlock::select()
{
    this->selected = true;
    this->onSelected();
}

void InteractableBlock::deselect()
{
    this->selected = false;
    this->onDeselected();
}

void InteractableBlock::enable()
{
    this->interactable = true;
    this->onEnabled();
}

void InteractableBlock::disable()
{
    this->interactable = false;
    this->onDiabled();
}