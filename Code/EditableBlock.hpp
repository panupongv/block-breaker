#pragma once

#include "TemplateBlock.hpp"
#include <vector>

class EditableBlock : public TemplateBlock
{
public:
    EditableBlock(TemplateBlock temp_block , int grid_x , int grid_y );
    virtual void update();//Game& game
    
protected:
    //abstract implementation
    virtual void onSelected();
    virtual void onDeselected();
    virtual void onEnabled();
    virtual void onDisabled();
    
private:
    int grid_x;
    int grid_y;
    std::vector<sf::Vector2i> movement;
};