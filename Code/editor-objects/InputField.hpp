#pragma once
#include "TextObject.hpp"
#include "SpriteObject.hpp"
#include "EventHandler.hpp"
#include "Selectable.hpp"
#include <string>

class InputField : public SpriteObject , public Selectable
{
public:
    InputField(std::string name , RenderLayer layer , std::string texture_name);
    
    std::string getText() const;
    void setTextSize( int font_size );
    void setTextColor( sf::Color color);
    
    
//    virtual void onSelected();
//    virtual void onDeselected();
    
    //polymorphism
    virtual void update( EventHandler& e );
    virtual void draw( sf::RenderWindow& window );
    virtual void enable();
    virtual void disable();
    
private:
    TextObject textObject;
    std::string current_text;
    std::string typing_symbol = "I";
    int blink_delay = 10;
    const sf::Color color_selected = sf::Color(255,255,255,130);
    const sf::Color color_deselected = sf::Color(255,255,255,100);
    
    void update_check_selected(EventHandler& e);
    void update_text ( EventHandler& e );
    void update_representation( EventHandler& e );
};
