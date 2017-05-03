/*
 editor-objects/SelectionAura.cpp
*/

#include "SelectionAura.hpp"

using namespace std;

SelectionAura::SelectionAura()
:SpriteObject("selection aura" , RenderLayer::EditingSpaceAuraLayer, "selection-aura.png")
{}

void SelectionAura::update(EventHandler &e)
{
    update_blink();
}

void SelectionAura::update_position( sf::Vector2f& parent_pos )
{
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
