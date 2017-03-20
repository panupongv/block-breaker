#pragma once

#include "SelectableBlock.hpp"
#include "Clickable.hpp"
#include "BlockData.hpp"

class TemplateBlock : public SelectableBlock , public Clickable
{
public:
    TemplateBlock(BlockType type,sf::Color color, float x , float y);
    virtual void update();//Game& game TODO
    BlockType getType();
    sf::Color getColor();
    
protected:
    //abstract implementation
    virtual void onSelected();
    virtual void onDeselected();
    virtual void onEnabled();
    virtual void onDisabled();
    
private:
    BlockType type;
    sf::Color color;
};