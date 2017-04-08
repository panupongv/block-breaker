#pragma once

#include "BaseObject.hpp"


class TextObject: public BaseObject {
public: 
    
    TextObject(std::string name , RenderLayer layer, std::string text, float x , float y);
    
    void setText(std::string text);
    std::string getText() const;
    void setSize(int font_size);
    int getSize() const;
    
    virtual void update(void* ptr);
    virtual void draw(sf::RenderWindow &window);
    
    virtual void setPosition(float x, float y, PositioningMode mode= PositioningMode::TopLeft);
    virtual sf::Vector2f getPosition(PositioningMode mode = PositioningMode::TopLeft) const;
    virtual void move(float x, float y);
    virtual void setColor(const sf::Color& color);
    virtual sf::Color getColor() const;
    
private: 
    sf::Text textRender;
    std::string name;
};
