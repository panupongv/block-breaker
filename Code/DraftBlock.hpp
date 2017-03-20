#pragma once

#ifdef __APPLE__
#include <SFML/Graphics.hpp>
#else
#include <SFML\Graphics.hpp>
#endif

#include "TemplateBlock.hpp"

class DraftBlock : public Block
{
public:
    DraftBlock(TemplateBlock tb);
    virtual void update();//TODO
    bool isAvailable();
    void setAvailability(bool available);
    sf::Vector2i getMagnetGrid( float x, float y);
    
private:
    const sf::Uint8 transparency = 128;
    bool available = false;
};