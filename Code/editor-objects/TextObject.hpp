/*
 base/TextObject.hpp
*/

#pragma once

#include "BaseObject.hpp"


class TextObject: public BaseObject {
public: 
    TextObject();
    TextObject(std::string name , RenderLayer layer, std::string text , std::string fontName = "sansation.ttf" );
    
    //setters
    void setText(std::string text);
    void setSize(int font_size);
    void setFont(std::string fontName);
    virtual void enable();
    virtual void disable();
    
    //getters
    sf::Text& getTextRender();
    std::string getText() const;
    int getSize() const;
    
    //abstract setters, mutators
    virtual void setPosition(float x, float y, PositioningMode mode= PositioningMode::TopLeft);
    virtual void setColor(sf::Color color);
    virtual void move(float x, float y);
    
    //abstract getters
    virtual sf::Vector2f getPosition(PositioningMode mode = PositioningMode::TopLeft) const;
    virtual const sf::Color getColor() const;
    virtual const sf::FloatRect getRect() const;
    
    //polymorphism behaviors
    virtual void update(EventHandler& e);
    virtual void draw(sf::RenderTarget &target);
    
private:
    sf::Text textRender;
    sf::Font font;
    sf::Color color = sf::Color::White;
};
