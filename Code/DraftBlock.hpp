#pragma once

#ifdef __APPLE__
#include <SFML/Graphics.hpp>
#else
#include <SFML\Graphics.hpp>
#endif

#include "Block.cpp"

class DraftBlock : public Block
{
public:
    DraftBlock();//TODO
    virtual void update();//TODO
    void setAvailability(bool available);
    sf::Vector2i getMagnetGrid( float x, float y);
    
private:
    const sf::Uint8 transparency = 128;
    bool available = false;
};