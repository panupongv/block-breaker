#pragma once

#include "SpriteObject.hpp"
#include "BlockData.hpp"

class DraftBlock: public SpriteObject
{
public: 
    
    DraftBlock();
    DraftBlock( std::string textureName , sf::Color color );
    
    //getter setter
    void setAvailability(bool available);
    bool getAvailability() const;

    //overwrite
    virtual void setColor( sf::Color color );
    
    //polymorphysm
    virtual void update( void* ptr );
    
private: 
    const float transparency = 0.5;
    bool available = true;
};
