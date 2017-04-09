#include "DraftBlock.hpp"
#include "ScreenSetting.hpp"

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
//    color.a = 255*this->transparency;
    SpriteObject::setColor(color);
}

void DraftBlock::update(void *ptr)
{
    SpriteObject::update(ptr);
    
    followCursor();
//    cout << mouse_position.x << endl;
    
    //todo : check availability
}

void DraftBlock::followCursor()
{
    sf::Vector2i mouse_position;
    mouse_position = sf::Mouse::getPosition(*(this->window));
    float ratio = ScreenSetting::ratio;
    this->setPosition(mouse_position.x/ratio, mouse_position.y/ratio,PositioningMode::Center);
}
