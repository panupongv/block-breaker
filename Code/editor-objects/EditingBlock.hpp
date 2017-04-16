#pragma once
#include "SpriteObject.hpp"
#include "BlockData.hpp"
#include "Selectable.hpp"
#include "Scene.hpp"

class EditingBlock;

class SelectionAura : public SpriteObject
{
public:
    SelectionAura(EditingBlock* parent);
    
    virtual void update(EventHandler& e);
    
private:
    void update_position();
    void update_blink();
    
private:
    const int blink_period = 5;
    
    EditingBlock* parent;
    int blink_timer = 0;
};

class EditingBlock : public SpriteObject, public BlockData, public Selectable
{
public:
    EditingBlock( TemplateData template_data , sf::Vector2i grid_pos , sf::Vector2i movement , Scene& scene);
    EditingBlock( BlockData block_data ,Scene& scene);
    ~EditingBlock( );
    
    virtual const sf::Color getColor( ) const;
    virtual void setColor( sf::Color color );
    
protected:
    virtual void onSelected();
    virtual void onDeselected();
    
private:
    Scene& scene;
    SelectionAura aura;
};
