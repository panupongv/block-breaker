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
    DraftBlock()//TODO
    virtual void update(Game& game);
    
private:
    const sf::Uint8 transparency = 128;
    bool available = false;
};