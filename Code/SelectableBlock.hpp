#pragma once

#include "Block.hpp"
#include <string>

class SelectableBlock : public Block
{
public:
    SelectableBlock(std::string texture_name , float x , float y);
    SelectableBlock(BlockType type , float x , float y );
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
    
private:
    bool selected = false;
    bool interactable = true;
};