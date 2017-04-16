#include "EditingBlock.hpp"

using namespace std;

SelectionAura::SelectionAura(EditingBlock* parent)
:SpriteObject("selection aura" , RenderLayer::EditingSpaceAuraLayer, "selection-aura.png")
,parent(parent)
{}

void SelectionAura::update(EventHandler &e)
{
    update_position();
    update_blink();
}

void SelectionAura::update_position()
{
    sf::Vector2f parent_pos = parent->getPosition();
    setPosition(parent_pos.x, parent_pos.y);
}

void SelectionAura::update_blink()
{
    blink_timer++;
    if(blink_timer < blink_period)
        setColor(sf::Color(255,255,255,220));
    else if ( blink_timer < blink_period*2)
        setColor(sf::Color::Transparent);
    else
        blink_timer = 0;
}
