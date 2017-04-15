#pragma once

#include "sfml.hpp"
#include "EventHandler.hpp"
#include "enums.hpp"

#include <string>

class EventHandler;

class BaseObject
{
public:
    BaseObject();
    BaseObject(std::string name, RenderLayer layer);
    
    //getters
    std::string getName() const;
    RenderLayer getLayer() const;
    virtual bool isActive() const;
    
    //setters - mutators
    void setLayer(RenderLayer layer);
    virtual void enable();
    virtual void disable();
    
    //abstract setters,mutators
    virtual void setPosition(float x, float y, PositioningMode mode = PositioningMode::TopLeft) = 0;
    virtual void setColor(sf::Color color) = 0;
    virtual void move(float x, float y) = 0;
    
    //abstract getters
    virtual sf::Vector2f getPosition(PositioningMode mode = PositioningMode::TopLeft) const = 0;
    virtual const sf::Color getColor() const = 0;
    virtual const sf::FloatRect getRect() const = 0;
    
    //polymorphism behaviors
    virtual void update(EventHandler& e) = 0;
    virtual void draw(sf::RenderTarget& target) = 0;
    
private: 
    std::string name = "unnamed base object";
    RenderLayer layer = RenderLayer::BackgroundLayer;
    bool active = true;
};
