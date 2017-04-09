#pragma once

#include "BaseObject.hpp"

class SpriteObject: public BaseObject
{
public: 
    SpriteObject();
    SpriteObject( std::string name , RenderLayer layer, std::string textureName , float x, float y);
    
    SpriteObject( std::string name , RenderLayer layer,std::string textureSheetName, float x , float y , int width , int height);
    
    sf::Sprite& getSprite();
    
    void setFrame( int frame_id );
    
    void nextFrame();
    
    void resetFrame();
    
    bool insideRect(float x, float y) const;
    
    virtual void update(void* ptr);
    virtual void draw(sf::RenderWindow& window);
    virtual void setPosition(float x, float y, PositioningMode mode = PositioningMode::TopLeft);
    virtual sf::Vector2f getPosition(PositioningMode mode = PositioningMode::TopLeft) const;
    virtual void move(float offset_x, float offset_y);
    virtual void setColor(const sf::Color& color);
    virtual sf::Color getColor() const;
    
private:
    sf::Sprite sprite;
    sf::Texture texture;
    int current_frame = 0;
    int num_row;
    int num_col;
    int width;
    int height;
    
    void setTexture(std::string textureName);
    void setTextureSheet(std::string textureSheetName , int width , int height );
    void applyCurrentFrame();
    int getNumFrame() const;
    int getCurrentRow() const;
    int getCurrentColumn() const;
};
