#pragma once
#include "sfml.hpp"
#include "BaseObject.hpp"
#include <string>
#include <vector>

class MinorEventHandler;
class MouseEventHandler;
class KeyEventHandler;

class EventHandler
{
public:
    EventHandler( sf::RenderWindow& window );
    ~EventHandler();
    void poll( sf::Event& event );
    bool gotClickOn(const BaseObject& object , sf::Mouse::Button button = sf::Mouse::Left) const;
    bool gotClickOn(const sf::FloatRect& rect , sf::Mouse::Button button = sf::Mouse::Left) const;
    bool gotKey(sf::Keyboard::Key key) const;
    std::string getString() const;
    bool wasClosed() const;

private:
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
    bool gotClickOn(const sf::FloatRect rect , sf::Mouse::Button button = sf::Mouse::Left ) const;
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
