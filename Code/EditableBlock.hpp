#pragma once

#include "BlockData.hpp"
#include "Block.hpp"
#include "InteractableObject.hpp"
#include "SnappableObject.hpp"
#include <vector>

class EditableBlock : public Block , public InteractableObject , public SnappableObject
{
public:
    EditableBlock(BlockData data);
    EditableBlock(TemplateData data , int grid_x , int grid_y );
    EditableBlock(TemplateData data , float x , float y );
    EditableBlock(BlockType type , sf::Color color , sf::Vector2i startGrid );
    EditableBlock(BlockType type , sf::Color color , int grid_x , int grid_y );
    EditableBlock(BlockType type , sf::Color color , float x , float y );

    virtual void update();//Game& game

protected:
    //abstract implementation
    virtual void onSelected();
    virtual void onDeselected();
    virtual void onEnabled();
    virtual void onDisabled();
    virtual void onLeftClick();
    virtual void onRightClick();
    
private:
    BlockData data;
    std::vector<sf::Vector2i> movement;
};