/*
 group-object/ColorPalatte.hpp
*/

#pragma once

#include "ColorButton.hpp"
#include "EventHandler.hpp"
#include "enums.hpp"
#include "Scene.hpp"
#include <vector>

class ColorPalatte
{
public:
    ColorPalatte( float pos_x, float pos_y , float size_y , int color_num , Scene& scene );
    void update( EventHandler& e );
    void enable();
    void disable();
    bool gotClick ( EventHandler& e ) const;
    sf::Color getSelectedColor() const;
    
private:
    void update_detect_click(EventHandler& e);
    void deselect_all_color_button();
    
private:
    sf::Color selectedColor = sf::Color::White;
    std::vector<ColorButton*> buttons;
    
};
