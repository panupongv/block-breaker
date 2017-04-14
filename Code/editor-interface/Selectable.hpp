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
    virtual void onSelected();
    virtual void onDeselected();
    
private:
    bool selected = false;
};
