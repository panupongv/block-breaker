/*
 helper/EventHandler.cpp
*/

#include "EventHandler.hpp"
#include "WindowHelper.hpp"
#include <iostream>

using namespace std;

//EVENT HANDLER
EventHandler::EventHandler( sf::RenderWindow& window )
: window(window)
{
    this->mouseEventHandler = new MouseEventHandler(window);
    this->keyEventHandler = new KeyEventHandler(window);
}

EventHandler::~EventHandler()
{
    delete this->mouseEventHandler;
    delete this->keyEventHandler;
}

void EventHandler::poll(sf::Event &event)
{
    if(mouseEventHandler->acceptEventType(event.type))
        mouseEventHandler->poll(event);
    
    if(keyEventHandler->acceptEventType(event.type))
        keyEventHandler->poll(event);
    
    if(event.type == sf::Event::Closed)
        closed = true;
}

bool EventHandler::cursorOn(const BaseObject* object) const
{
    return cursorOn(*object);
}

bool EventHandler::cursorOn(const BaseObject &object) const
{
    if(object.isActive() == false)
        return false;
    return cursorOn(object.getRect());
}

bool EventHandler::cursorOn(const sf::FloatRect &rect) const
{
    sf::Vector2f mouse_pos = WindowHelper::getMousePosition(window);
    return rect.contains(mouse_pos);
}

float EventHandler::gotWheelOn(const BaseObject *object) const
{
    return gotWheelOn(*object);
}

float EventHandler::gotWheelOn(const BaseObject &object) const
{
    return gotWheelOn(object.getRect());
}

float EventHandler::gotWheelOn(const sf::FloatRect &rect) const
{
    return mouseEventHandler->gotWheelOn(rect);
}

bool EventHandler::gotClickOn(const BaseObject* object , sf::Mouse::Button button) const
{
    return gotClickOn(*object,button);
}

bool EventHandler::gotClickOn(const BaseObject& object , sf::Mouse::Button button) const
{
    if(object.isActive() == false)
        return false;
    
    return gotClickOn(object.getRect(),button);
}

bool EventHandler::gotClickOn(const sf::FloatRect &rect, sf::Mouse::Button button) const
{
    return mouseEventHandler->gotClickOn(rect,button);
}

bool EventHandler::gotDragOn(const BaseObject* object,sf::Mouse::Button button) const
{
    return this->gotDragOn(*object , button);
}

bool EventHandler::gotDragOn(const BaseObject &object,sf::Mouse::Button button) const
{
    if(object.isActive() == false)
        return false;
    
    return this->gotDragOn(object.getRect(),button);
}

bool EventHandler::gotDragOn(const sf::FloatRect &rect , sf::Mouse::Button button) const
{
    bool mouse_down = sf::Mouse::isButtonPressed(button);
    bool mouse_on = cursorOn(rect);
    
    return mouse_on && mouse_down;
}

bool EventHandler::gotKey(sf::Keyboard::Key key) const
{
    return keyEventHandler->gotKey(key);
}

bool EventHandler::gotKeyHold(sf::Keyboard::Key key) const
{
    return sf::Keyboard::isKeyPressed(key);
}

std::string EventHandler::getString() const
{
    return keyEventHandler->getTextEntered();
}

bool EventHandler::wasClosed() const
{
    return closed;
}

//MINOR EVENT HANDLER
MinorEventHandler::MinorEventHandler(sf::RenderWindow& window)
: window(window) { }

void MinorEventHandler::poll(sf::Event& event)
{
    if(this->acceptEventType(event.type))
        this->events.push_back(event);
    else
        throw invalid_argument("unacceptable event type added");
}

bool MinorEventHandler::any(sf::Event::EventType type) const
{
    for(int i = 0 ;i < events.size() ; ++i)
    {
        if(events[i].type == type)
            return true;
    }
    
    return false;
}

bool MinorEventHandler::no_any(sf::Event::EventType type) const
{
    return !any(type);
}

bool MinorEventHandler::any_mouse(sf::Mouse::Button button) const
{
    for(int i = 0 ; i < events.size();  i++)
        if(events[i].mouseButton.button == button)
            return true;
    
    return false;
}

bool MinorEventHandler::any_key(sf::Keyboard::Key key) const
{
    for(int i = 0 ; i < events.size();  i++)
        if(events[i].key.code == key)
            return true;
    
    return false;
}

//MOUSE EVENT HANDLER
MouseEventHandler::MouseEventHandler(sf::RenderWindow& window)
: MinorEventHandler(window) { }

bool MouseEventHandler::acceptEventType(sf::Event::EventType type) const
{
    switch (type) {
        case sf::Event::EventType::MouseButtonPressed :
            return true;
            
        case sf::Event::EventType::MouseButtonReleased :
            return true;
            
        case sf::Event::EventType::MouseLeft :
            return true;
            
        case sf::Event::EventType::MouseMoved :
            return true;
            
        case sf::Event::EventType::MouseEntered :
            return true;
            
        case sf::Event::EventType::MouseWheelScrolled :
            return true;
            
        default:
            return false;
    }
}

float MouseEventHandler::gotWheelOn(const sf::FloatRect &rect) const
{
    sf::Vector2f mouse_pos = WindowHelper::getMousePosition(window);
    
    if(rect.contains( mouse_pos ) )
    {
        if(any(sf::Event::MouseWheelScrolled))
            return gotScrolled();
    }
        
    return 0;
}


bool MouseEventHandler::gotClickOn(const sf::FloatRect rect ,sf::Mouse::Button button) const
{
    if(any(sf::Event::EventType::MouseButtonPressed))
        if(any_mouse(button))
        {
            sf::Vector2f mouse_pos = WindowHelper::getMousePosition(window);
    
            return rect.contains( mouse_pos );
        }
    
    return false;
}

//this feature( wheel scrolling ) does not work on Mac OSX
int MouseEventHandler::gotScrolled() const
{
    int scrolled = 0;
    for(int i = 0 ; i < events.size() ; i++)
    {
        sf::Event event = events[i];
        if(event.type == sf::Event::MouseWheelScrolled)
        {
            scrolled += event.mouseWheel.delta;
        }
    }
    
    return scrolled;
}

//KEY EVENT HANDLER
KeyEventHandler::KeyEventHandler(sf::RenderWindow& window)
: MinorEventHandler(window) { }

bool KeyEventHandler::acceptEventType(sf::Event::EventType type) const
{
    switch (type) {
        case sf::Event::EventType::KeyPressed :
            return true;
            
        case sf::Event::EventType::KeyReleased :
            return true;
            
        case sf::Event::EventType::TextEntered :
            return true;
            
        default:
            return false;
    }
}

bool KeyEventHandler::gotKey(sf::Keyboard::Key key) const
{
    if(any(sf::Event::EventType::KeyPressed))
        if(any_key(key))
            return true;
    
    return false;
}

string KeyEventHandler::getTextEntered() const
{
    string result;
    
    for(int i = 0 ; i < events.size() ; i++)
    {
        if(events[i].type == sf::Event::TextEntered)
            result += events[i].text.unicode;
    }
    
    return result;
}
