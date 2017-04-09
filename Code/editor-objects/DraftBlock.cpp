#include "DraftBlock.hpp"

using namespace std;

DraftBlock::DraftBlock( string textureName , sf::Color color )
:SpriteObject("draft block" , RenderLayer::Foreground , textureName )
{
    this->setColor(sf::Color::White);
}

void DraftBlock::setAvailability(bool available)
{
    this->available = available;
}

bool DraftBlock::getAvailability() const
{
    return this->available;
}

void DraftBlock::setColor(sf::Color color)
{
    color.a = 255*this->transparency;
    SpriteObject::setColor(color);
}

void DraftBlock::update(void *ptr)
{
    SpriteObject::update(ptr);
    
    sf::Vector2i mouse_position;
    mouse_position = sf::Mouse::getPosition();
    setPosition(mouse_position.x, mouse_position.y);
    
    //todo : check availability
}
