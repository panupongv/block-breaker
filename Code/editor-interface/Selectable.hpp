#pragma once

//abstract for multiple inheritance
class Selectable
{
public:
    Selectable();
    
    bool isSelected() const;
    void select();
    void deselect();

protected:
    virtual void onSelected() = 0;
    virtual void onDeselected() = 0;
    
private:
    bool selected = false;
};
