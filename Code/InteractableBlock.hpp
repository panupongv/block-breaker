#pragma once

#include "Block.hpp"
#include <string>

class InteractableBlock : public Block
{
public:
    InteractableBlock(std::string texture_name , float x , float y);
    InteractableBlock(BlockType type , float x , float y );
    bool isSelected();
    bool isInteractable();
    void select();
    void deselect();
    void enable();
    void disable();
    
protected:
    virtual void onSelected() = 0;
    virtual void onDeselected() = 0;
    virtual void onEnabled() = 0;
    virtual void onDiabled() = 0;
    virtual void onClickLeft() = 0;
    virtual void onClickRight() = 0;
    
private:
    bool selected = false;
    bool interactable = true;
};