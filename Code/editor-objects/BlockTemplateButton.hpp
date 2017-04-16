#pragma once
#include "SpriteObject.hpp"
#include "Selectable.hpp"
#include "TemplateData.hpp"
#include "sfml.hpp"

class BlockTemplateButton : public SpriteObject , public Selectable, public TemplateData
{
public:
    BlockTemplateButton(std::string name , RenderLayer layer , BlockType type );
    
    virtual void setPosition( float x, float y );
    virtual void setColor( sf::Color color );
    //polymorphism
    virtual void update(EventHandler& e);
    
private:
    float normal_x = 0;
    float normal_y = 0;
    
    std::string texture_name_of( BlockType type ) const;
};
