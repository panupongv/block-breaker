#pragma once

#include "BaseObject.hpp"

class SpriteObject: public BaseObject
{
public: 
    SpriteObject();
    SpriteObject( std::string name , RenderLayer layer, std::string textureName );
    SpriteObject( std::string name , RenderLayer layer , std::string textureSheetName , int width , int height);
    
    //getters
    sf::Sprite& getSprite();
    
    //mutators
    void setFrame( int frame_id );
    void nextFrame( );
    void resetFrame( );
    virtual void enable();
    virtual void disable();
    
    //queries
    bool insideRect( float x, float y ) const;
    
    //abstract
    virtual void setPosition( float x, float y, PositioningMode mode = PositioningMode::TopLeft );
    virtual sf::Vector2f getPosition( PositioningMode mode = PositioningMode::TopLeft ) const;
    virtual void setColor( const sf::Color& color );
    virtual const sf::Color getColor( ) const;
    virtual const sf::FloatRect getRect() const;
    virtual void move( float offset_x, float offset_y );
    
    //polymorphysm
    virtual void update(EventHandler& e );
    virtual void draw( sf::RenderWindow& window );
    
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Color color = sf::Color::White;
    int current_frame = 0;
    int num_row;
    int num_col;
    int width;
    int height;
    
    //mutators
    void setTexture(std::string textureName);
    void setTextureSheet(std::string textureSheetName , int width , int height );
    void applyCurrentFrame();
    
    //queries
    int getNumFrame() const;
    int getCurrentRow() const;
    int getCurrentColumn() const;
};
