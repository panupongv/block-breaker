/*
 editor-objects/EditingBlock.hpp
*/

#pragma once
#include "SpriteObject.hpp"
#include "BlockData.hpp"
#include "Selectable.hpp"
#include "Scene.hpp"
#include "SelectionAura.hpp"
#include "Pin.hpp"

class EditingBlock : public SpriteObject, public BlockData, public Selectable
{
public:
    EditingBlock( TemplateData template_data , sf::Vector2i grid_pos , sf::Vector2i movement , Scene& scene);
    EditingBlock( BlockData block_data ,Scene& scene);
    ~EditingBlock( );
    
    virtual const sf::Color getColor( ) const;
    virtual void setColor( sf::Color color );
//    virtual void setStartGrid( sf::Vector2i grid );
//    virtual void setStartGrid( int x , int y );
    
    virtual void update(EventHandler& e);
    
protected:
    virtual void onSelected();
    virtual void onDeselected();
    
private:
    Scene& scene;
    SelectionAura aura;
    Pin pin;
};
