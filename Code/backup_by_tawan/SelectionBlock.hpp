#pragma once
#include "SnappableObject.hpp"
#include "InteractableObject.hpp"
#include "TemplateBlock.hpp"

class SelectionBlock : public TemplateBlock , public SnappableObject , public InteractableObject
{
public:
    SelectionBlock( BlockType type , sf::Color color , float x , float y );
    SelectionBlock( BlockType type , sf::Color color , int gx , int gy );
    SelectionBlock( TemplateData data , float x , float y );
    SelectionBlock( TemplateData data , int gx , int gy );
    
    virtual void update();//Game& game
protected:
    //abstract implementation
    virtual void onSelected();
    virtual void onDeselected();
    virtual void onEnabled();
    virtual void onDisabled();
    virtual void onLeftClick();
    virtual void onRightClick();
};