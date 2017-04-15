#include "ColorPalatte.hpp"
#include <iostream>

using namespace std;

ColorPalatte::ColorPalatte( float pos_x, float pos_y , float size_y , int color_num , Scene& scene )
{
    float color_size_y = size_y / color_num;
    
    for(int i = 0 ; i < color_num ; i++)
    {
        buttons.push_back(new ColorButton("color button",RenderLayer::PanelElementLayer,i,color_num));
        buttons[i]->getSprite().setScale(1, color_size_y);
        buttons[i]->setPosition(pos_x, pos_y);
        scene.addObject(buttons[i]);
    }
}

void ColorPalatte::update(EventHandler &e)
{
    update_detect_click(e);
}


void ColorPalatte::enable()
{
    for(int i = 0 ; i < buttons.size() ; ++i)
    {
        buttons[i]->enable();
    }
}

void ColorPalatte::disable()
{
    for(int i = 0 ; i < buttons.size() ; ++i )
        buttons[i]->disable();
}

bool ColorPalatte::gotClick(EventHandler &e) const
{
    sf::FloatRect rect;
    rect.left = buttons[0]->getRect().left;
    rect.width = buttons[0]->getRect().width;
    rect.top = buttons[0]->getRect().top;
    rect.height = buttons[0]->getRect().height*buttons.size();
    
    if(e.gotClickOn(rect))
        return true;
    
    return false;
}

void ColorPalatte::deselect_all_color_button()
{
    for(int i =  0 ; i < buttons.size() ; i++)
        buttons[i]->deselect();
}

void ColorPalatte::update_detect_click(EventHandler& e)
{
    for(int i = 0 ; i < buttons.size() ; i++)
    {
        if(e.gotClickOn(buttons[i]))
        {
            deselect_all_color_button();
            buttons[i]->select();
            selectedColor = buttons[i]->getColor();
            return;
        }
    }
}

sf::Color ColorPalatte::getSelectedColor() const
{
    return selectedColor;
}
