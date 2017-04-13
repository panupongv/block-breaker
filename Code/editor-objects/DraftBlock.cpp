#include "DraftBlock.hpp"
#include "WindowHelper.hpp"

using namespace std;

DraftBlock::DraftBlock( string textureName , sf::RenderWindow& window , sf::Color color )
:SpriteObject("draft block" , RenderLayer::Foreground , textureName )
{
    this->setColor( color );
    this->window = &window;
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
    
    followCursor();
}

void DraftBlock::followCursor()
{
    sf::Vector2f mouse_position = WindowHelper::getMousePosition( *window );
    this->setPosition(mouse_position.x,mouse_position.y,PositioningMode::Center);
}
