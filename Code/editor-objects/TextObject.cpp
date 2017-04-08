#include "TextObject.hpp"

using namespace std;

TextObject::TextObject(string name , RenderLayer layer, string text, float x , float y)
:BaseObject(name , layer)
{
    this->setText(text);
    this->setPosition(x, y);
}

void TextObject::setText(string text) {
    this->textRender.setString(text);
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
    this->textRender.getCharacterSize();
}

void TextObject::update(void *ptr)
{
    return;
}

void TextObject::draw(sf::RenderWindow &window)
{
    window.draw(this->textRender);
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

void TextObject::setColor(const sf::Color &color)
{
    this->textRender.setFillColor(color);
}

sf::Color TextObject::getColor() const
{
    return this->textRender.getFillColor();
}