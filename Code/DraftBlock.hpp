#pragma once

#ifdef __APPLE__
#include <SFML/Graphics.hpp>
#else
#include <SFML\Graphics.hpp>
#endif

#include "TemplateBlock.hpp"

class DraftBlock : public TemplateBlock
{
public:
    DraftBlock(TemplateBlock tb);
    bool isAvailable();
    void setAvailability(bool available);
    
    virtual void update();//TODO
    
private:
    const sf::Uint8 transparency = 128;
    bool available = false;
};