/*
 base/TextObject.cpp
*/

#include "TextObject.hpp"
#include "ResourcePath.hpp"
#include <iostream>

using namespace std;

TextObject::TextObject(string name , RenderLayer layer, string text, string fontName )
:BaseObject(name , layer)
{
    this->setFont( fontName );
    this->setText( text );
    this->setPosition( 0 , 0 );
}

void TextObject::setText(string text) {
    this->textRender.setString(text);
}

sf::Text& TextObject::getTextRender()
{
    return textRender;
}

string TextObject::getText() const
{
    return this->textRender.getString();
}

void TextObject::setSize(int font_size)
{
    this->textRender.setCharacterSize(font_size);
}

int TextObject::getSize() const
{
    return this->textRender.getCharacterSize();
}

const sf::FloatRect TextObject::getRect() const
{
    return this->textRender.getGlobalBounds();
}
void TextObject::setFont(std::string fontName)
{
    if(this->font.loadFromFile(resourcePath() + fontName))
       this->textRender.setFont(this->font);
    else
       throw invalid_argument("cannot find font : " + fontName );
}

void TextObject::enable()
{
    BaseObject::enable();
    this->setColor(this->color);
}

void TextObject::disable()
{
    //must use built in
    textRender.setFillColor(sf::Color(0,0,0,0));
    BaseObject::disable();
}

void TextObject::update(EventHandler& e)
{
    return;
}

void TextObject::draw(sf::RenderTarget &target)
{
    if(this->isActive())
    {
//        cout << "draw " << getName() << endl;
//        cout << (int)textRender.getFillColor().a << endl;
        target.draw(this->textRender);
    }
}

void TextObject::setPosition(float x,float y,PositioningMode mode )
{
    if(mode == PositioningMode::TopLeft)
        this->textRender.setPosition(x, y);
    else if(mode == PositioningMode::Center)
    {
        sf::FloatRect bound = this->textRender.getGlobalBounds();
        
        float x_mid,y_mid;
        x_mid = bound.width/2;
        y_mid = bound.height/2;
        
        this->textRender.setPosition(x-x_mid, y-y_mid);
    }
}

sf::Vector2f TextObject::getPosition(PositioningMode mode) const
{
    if(mode == PositioningMode::TopLeft)
    {
        return this->textRender.getPosition();
    }
    else if( mode == PositioningMode::Center )
    {
        sf::Vector2f position = this->textRender.getPosition();
        sf::FloatRect bound = this->textRender.getGlobalBounds();
        
        position.x += bound.width/2;
        position.y += bound.height/2;
        
        return position;
    }
}

void TextObject::move(float x , float y )
{
    this->textRender.move(x, y);
}

void TextObject::setColor(sf::Color color)
{
    this->color = color;
    
    if(this->isActive())
    this->textRender.setFillColor(color);
}

const sf::Color TextObject::getColor() const
{
    return this->textRender.getFillColor();
}
