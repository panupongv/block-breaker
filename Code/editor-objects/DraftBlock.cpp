#include "DraftBlock.hpp"
#include "WindowHelper.hpp"

using namespace std;

DraftBlock::DraftBlock( string textureName , sf::RenderWindow& window , sf::Color color )
:SpriteObject("draft block" , RenderLayer::DraftBlockLayer , textureName )
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

void DraftBlock::update( EventHandler& e )
{
    SpriteObject::update(e);
    
    followCursor();
    snapToGrid();
}

void DraftBlock::draw(sf::RenderWindow &window)
{
    if(getAvailability() == true)
        SpriteObject::draw(window);
}

void DraftBlock::followCursor()
{
    sf::Vector2f mouse_position = WindowHelper::getMousePosition( *window );
    this->setPosition(mouse_position.x,mouse_position.y);
}

void DraftBlock::snapToGrid()
{
    sf::Vector2f position = getPosition();
    int width = getSprite().getGlobalBounds().width;
    int height = getSprite().getGlobalBounds().height;
    position.x =  (int)position.x - (int)position.x%width;
    position.y =  (int)position.y - (int)position.y%height;
    
    setPosition(position.x, position.y);
}

