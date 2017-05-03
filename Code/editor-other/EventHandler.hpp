/*
 helper/EventHandler.hpp
*/

#pragma once
#include "sfml.hpp"
#include "BaseObject.hpp"
#include <string>
#include <vector>

class MinorEventHandler;
class MouseEventHandler;
class KeyEventHandler;

class BaseObject;
class EventHandler
{
public:
    EventHandler( sf::RenderWindow& window );
    ~EventHandler();
    void poll( sf::Event& event );
    
    float gotWheelOn(const BaseObject* object ) const;
    float gotWheelOn(const BaseObject& object ) const;
    float gotWheelOn(const sf::FloatRect& rect ) const;
    
    bool gotClickOn(const BaseObject* object , sf::Mouse::Button button = sf::Mouse::Left) const;
    bool gotClickOn(const BaseObject& object , sf::Mouse::Button button = sf::Mouse::Left) const;
    bool gotClickOn(const sf::FloatRect& rect , sf::Mouse::Button button = sf::Mouse::Left) const;
    
    bool cursorOn(const BaseObject* object ) const;
    bool cursorOn(const BaseObject& object) const;
    bool cursorOn(const sf::FloatRect& rect) const;
    
    bool gotDragOn(const BaseObject* object , sf::Mouse::Button button = sf::Mouse::Left) const;
    bool gotDragOn(const BaseObject& object , sf::Mouse::Button button = sf::Mouse::Left) const;
    bool gotDragOn(const sf::FloatRect& rect , sf::Mouse::Button button = sf::Mouse::Left) const;
    
    bool gotKey(sf::Keyboard::Key key) const;
    bool gotKeyHold(sf::Keyboard::Key key) const;
    std::string getString() const;
    
    bool wasClosed() const;

private:
    sf::RenderWindow& window;
    MouseEventHandler* mouseEventHandler;
    KeyEventHandler* keyEventHandler;
    bool closed = false;
};

//should be inherited for only 1 level
class MinorEventHandler
{
public:
    MinorEventHandler();
    MinorEventHandler(sf::RenderWindow& window);
    
    virtual void poll(sf::Event& event);
    bool any(sf::Event::EventType type) const;
    bool no_any(sf::Event::EventType type) const;
    bool any_mouse(sf::Mouse::Button button) const;
    bool any_key(sf::Keyboard::Key button) const;
    virtual bool acceptEventType(sf::Event::EventType type) const = 0;
    
protected:
    std::vector<sf::Event> events;
    sf::RenderWindow& window;
};

class MouseEventHandler: public MinorEventHandler
{
public:
    MouseEventHandler();
    MouseEventHandler(sf::RenderWindow& window);
    
    virtual bool acceptEventType(sf::Event::EventType type) const;
    float gotWheelOn(const sf::FloatRect& rect ) const;
    bool gotClickOn(const sf::FloatRect rect , sf::Mouse::Button button = sf::Mouse::Left ) const;
    
private:
    int gotScrolled() const;
};

class KeyEventHandler: public MinorEventHandler
{
public:
    KeyEventHandler();
    KeyEventHandler(sf::RenderWindow& window);
    
    virtual bool acceptEventType(sf::Event::EventType type) const;
    bool gotKey(sf::Keyboard::Key key) const;
    std::string getTextEntered() const;
};

