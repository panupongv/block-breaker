#pragma once

#include <string>

//abstract class
class InteractableObject
{
public:
    virtual ~InteractableObject() = 0; // mark abstract
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