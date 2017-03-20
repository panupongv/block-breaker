#pragma once

#include "TemplateBlock.hpp"
#include <vector>

class EditableBlock : public TemplateBlock
{
public:
    EditableBlock(TemplateBlock temp_block , int grid_x , int grid_y );
    virtual void update();//Game& game
    
private:
    int grid_x;
    int grid_y;
    vector<sf::Vector2i> movement;
};