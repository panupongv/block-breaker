#pragma once
#include "SpriteObject.hpp"
#include "BlockData.hpp"
#include "Selectable.hpp"

class EditingBlock :
public SpriteObject,
public BlockData,
public Selectable
{
public:
    EditingBlock( TemplateData template_data , sf::Vector2i grid_pos , sf::Vector2i movement );
    EditingBlock( BlockData block_data );
    
    virtual const sf::Color getColor( ) const;
    virtual void setColor( sf::Color color );
private:
};
