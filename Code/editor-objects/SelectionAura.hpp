#include "SpriteObject.hpp"

class SelectionAura : public SpriteObject
{
public:
    SelectionAura();
    
    virtual void update(EventHandler& e);
    void update_position( sf::Vector2f& parent_pos );
    
private:
    void update_blink();
    
private:
    const int blink_period = 5;
    int blink_timer = 0;
};
