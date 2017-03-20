#pragma once

#include "SelectableBlock.hpp"
#include "Clickable.hpp"
#include "BlockData.hpp"

class TemplateBlock : public SelectableBlock , public Clickable
{
public:
    TemplateBlock(BlockType type,sf::Color color, float x , float y);
    virtual void update();//Game& game TODO
    
private:
    BlockType type;
    sf::Color color;
};