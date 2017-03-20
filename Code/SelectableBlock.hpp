#pragma once

#include "Block.hpp"

class SelectableBlock : public Block
{
public:
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
    bool selected;
    bool interactable;
};