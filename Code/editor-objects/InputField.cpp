/*
 editor-objects/InputField.cpp
*/

#include "InputField.hpp"
#include "WindowHelper.hpp"
#include "helperfunc.hpp"

#include <iostream>

using namespace std;

InputField::InputField( string name , RenderLayer layer, string texture_name )
:SpriteObject(name , layer, texture_name)
,textObject("input text",layer,""){ }

string InputField::getText() const
{
    return this->current_text;
}

void InputField::setTextSize(int font_size)
{
    textObject.setSize(font_size);
}

void InputField::setTextColor( sf::Color color )
{
    textObject.setColor(color);
}

void InputField::clearText()
{
    current_text = "";
}

void InputField::setText( string text )
{
    current_text = text;
}

void InputField::update(EventHandler& e)
{
    update_check_selected(e);
    
    if(isSelected())
        update_text(e);
    
    update_representation(e);
}

void InputField::draw(sf::RenderTarget &target)
{
    SpriteObject::draw(target);
    textObject.draw(target);
}

void InputField::enable()
{
    SpriteObject::enable();
    textObject.enable();
}

void InputField::disable()
{
    SpriteObject::disable();
    textObject.disable();
}

void InputField::update_check_selected(EventHandler &e)
{
    bool click_on_window = e.gotClickOn(sf::FloatRect(0,0,WindowHelper::res_x,WindowHelper::res_y));
    bool click_on_field = e.gotClickOn(this);
    
    if( !click_on_field && !click_on_window )
        return;
    
    if( click_on_field )
        this->select();
    
    if( click_on_window && !click_on_field )
        this->deselect();
}

void InputField::update_text(EventHandler &e)
{
    string input = e.getString();
    
    if(input.empty() == false)
    {
        if(input[0] == 8) //backspace
        {
            if(current_text.size() > 0 )
            current_text.erase(current_text.size()-1,1);
        }
        else
        {
            if(current_text.size() + input.size() <= limit_char)
                current_text += input;
        }
    }
}

void InputField::update_representation(EventHandler& e)
{
    static int count = 0;
    
    if(isSelected())
    {
        setColor(color_selected);
        
        count++;
        if(count <= blink_delay)
        textObject.setText(current_text + typing_symbol);
        else if ( count <= blink_delay*2 )
            textObject.setText(current_text);
        else
            count = 0;
    }
    else
    {
        setColor(color_deselected);
        textObject.setText(current_text);
    }
    
    sf::FloatRect field_rect = getRect();
    sf::Vector2f midPos = helper::getCenterOf(field_rect);
    textObject.setPosition(field_rect.left+7, field_rect.top+10,PositioningMode::TopLeft);
}
