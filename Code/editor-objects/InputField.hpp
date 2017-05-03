/*
 editor-objects/InputField.hpp
*/

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
    void clearText();
    void setText( std::string text );
    
    //polymorphism
    virtual void update( EventHandler& e );
    virtual void draw( sf::RenderTarget& target );
    virtual void enable();
    virtual void disable();
    
private:
    void update_check_selected(EventHandler& e);
    void update_text ( EventHandler& e );
    void update_representation( EventHandler& e );
    
private:
    TextObject textObject;
    std::string current_text;
    int blink_delay = 20;
    const std::string typing_symbol = "I";
    const sf::Color color_selected = sf::Color(255,255,255,130);
    const sf::Color color_deselected = sf::Color(255,255,255,100);
    const int limit_char = 20;
    
};
