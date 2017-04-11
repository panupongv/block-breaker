#pragma once

#include "sfml.hpp"
#include <string>

enum RenderLayer {Background , Midground , Foreground , Top};
enum PositioningMode { TopLeft , Center };

class BaseObject
{
public:
    BaseObject();
    BaseObject(std::string name, RenderLayer layer);
    
    //getters
    std::string getName() const;
    RenderLayer getLayer() const;
    
    //setters
    void setLayer(RenderLayer layer);
    
    //abstract setters,mutators
    virtual void setPosition(float x, float y, PositioningMode mode = PositioningMode::TopLeft) = 0;
    virtual void setColor(const sf::Color& color) = 0;
    virtual void move(float x, float y) = 0;
    
    //abstract getters
    virtual sf::Vector2f getPosition(PositioningMode mode = PositioningMode::TopLeft) const = 0;
    virtual sf::Color getColor() const = 0;
    
    //polymorphism behaviors
    virtual void update(void* ptr) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    
private: 
    std::string name = "unnamed base object";
    RenderLayer layer = RenderLayer::Background;
};
