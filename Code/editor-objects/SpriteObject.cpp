#include "SpriteObject.hpp"
#include "ResourcePath.hpp"
#include <exception>
#include <iostream>

using namespace std;

SpriteObject::SpriteObject(string name , RenderLayer layer, string textureName )
:BaseObject(name,layer)
{
    this->setTexture(textureName);
    this->setPosition(0, 0);
}

SpriteObject::SpriteObject(string name , RenderLayer layer , string textureSheetName , int width , int height )
:BaseObject(name , layer)
{
    this->setTextureSheet(textureSheetName, width, height);
    this->setPosition(0, 0);
}

sf::Sprite& SpriteObject::getSprite()
{
    return this->sprite;
}

void SpriteObject::setFrame(int frame_id )
{
    this->current_frame = frame_id;
    this->applyCurrentFrame();
}

void SpriteObject::nextFrame()
{
    this->current_frame++;
    this->current_frame %= this->getNumFrame();
    this->applyCurrentFrame();
}

void SpriteObject::resetFrame() {
    this->current_frame = 0;
    this->applyCurrentFrame();
}

void SpriteObject::enable()
{
    BaseObject::enable();
    this->setColor(this->color);
}

void SpriteObject::disable()
{
    //must use built-in
    this->sprite.setColor(sf::Color(0,0,0,0));
    BaseObject::disable();
}
bool SpriteObject::insideRect(float x, float y) const
{
    sf::FloatRect rect = this->sprite.getGlobalBounds();
    
    return
    x > rect.left &&
    x < rect.left + rect.width &&
    y > rect.top &&
    y < rect.top + rect.height;
}

void SpriteObject::setTexture(string textureName)
{
    this->texture = sf::Texture();
    this->texture.loadFromFile(resourcePath() + textureName);
    this->sprite.setTexture(texture);
    
    this->num_col = 1;
    this->num_row = 1;
    this->width = texture.getSize().x;
    this->height = texture.getSize().y;
    this->current_frame = 0;
}

void SpriteObject::setTextureSheet(string textureSheetName, int width, int height)
{
    this->texture = sf::Texture();
    texture.loadFromFile(resourcePath() + textureSheetName);
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(sf::IntRect(0,0,width,height));
    
    this->num_col = texture.getSize().x/width;
    this->num_row = texture.getSize().y/height;
    this->width = width;
    this->height = height;
    this->current_frame = 0;
}

void SpriteObject::applyCurrentFrame()
{
    int row = this->getCurrentRow();
    int column = this->getCurrentColumn();
    
    sf::IntRect frame
    (
        column*width,
        row*height,
        (column+1)*width,
        (row+1)*height
    );
    
    this->sprite.setTextureRect(frame);
}

int SpriteObject::getNumFrame()  const
{
    return this->num_row * this->num_col;
}

int SpriteObject::getCurrentRow() const
{
    return this->current_frame / this->num_col;
}

int SpriteObject::getCurrentColumn() const
{
    return this->current_frame % this->num_col;
}

void SpriteObject::update( EventHandler& e)
{
    return;
}

void SpriteObject::draw(sf::RenderTarget &target)
{
    if(this->isActive())
        target.draw(this->sprite);
}

void SpriteObject::setPosition(float x, float y , PositioningMode mode )
{
    if(mode == PositioningMode::TopLeft)
        this->sprite.setPosition(x, y);
    else if(mode == PositioningMode::Center)
    {
        float mid_x = x - this->width/2;
        float mid_y = y - this->height/2;
        this->sprite.setPosition(mid_x, mid_y);
    }
    else
    {
        throw invalid_argument("non defined positioning mode");
    }
}

sf::Vector2f SpriteObject::getPosition( PositioningMode mode ) const
{
    if(mode == PositioningMode::TopLeft)
        return this->sprite.getPosition();
    else if(mode == PositioningMode::Center)
    {
        sf::FloatRect rect = this->sprite.getGlobalBounds();
        float mid_x = rect.left + rect.width/2;
        float mid_y = rect.top + rect.height/2;
        return sf::Vector2f(mid_x,mid_y);
    }
    else
    {
        throw invalid_argument("non defined positioning mode");
    }
}

void SpriteObject::move(float offset_x, float offset_y)
{
    this->getSprite().move(offset_x,offset_y);
}

void SpriteObject::setColor(const sf::Color &color)
{
    this->color = color;
    
    if(this->isActive())
        this->getSprite().setColor(this->color);
}

const sf::Color SpriteObject::getColor() const
{
    return this->sprite.getColor();
}

const sf::FloatRect SpriteObject::getRect() const
{
    return this->sprite.getGlobalBounds();
}
