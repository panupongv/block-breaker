#pragma once
#include "SpriteObject.hpp"
#include "TextObject.hpp"

class ItemList : public SpriteObject
{
public:
    ItemList( std::string name , RenderLayer layer , std::string texture_name );
    
    void setList( std::vector<std::string> list );
    
    
    //polymorphism
    virtual void update( EventHandler& e );
    virtual void draw ( sf::RenderTarget& target );
    
private:
    std::vector<std::string> list;
};
