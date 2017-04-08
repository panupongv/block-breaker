#pragma once

#include "Block.hpp"
#include "TemplateData.hpp"

class TemplateBlock : public Block
{
public:
    TemplateBlock(BlockType type,sf::Color color, float x , float y);
    BlockType getType();
    sf::Color getColor();
    void setType( BlockType type);
    void setColor ( sf::Color color );
    
    virtual void update();//Game& game TODO 
    
    
private:
    TemplateData data;
};