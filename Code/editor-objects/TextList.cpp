#include "TextList.hpp"
#include "ResourcePath.hpp"
#include "WindowHelper.hpp"

#include <iostream>

using namespace std;

TextList::TextList ( string name , RenderLayer layer , string texture_name , sf::RenderWindow& window)
: SpriteObject( name , layer , texture_name ), window(window)
{ }

void TextList::setStringList( vector<string> list )
{
    string_list = list;
}

void TextList::setSpaceX(int space_x)
{
    this->space_x = space_x;
}

void TextList::setSpaceY(int space_y)
{
    this->space_y = space_y;
}

void TextList::scroll(float y)
{
    float min_shift = 0;
    float max_shift = getAvailableScroll();
    
    shift_y += y;
    
    if( shift_y < min_shift )
        shift_y = min_shift;
    
    if( shift_y > max_shift )
        shift_y = max_shift;
}

string TextList::getSelectedItem() const
{
    return selected_item;
}

int TextList::getSpaceX() const
{
    return space_x;
}

int TextList::getSpaceY() const
{
    return space_y;
}

int TextList::getTextSize() const
{
    return text_size;
}

int TextList::getNumList() const
{
    return string_list.size();
}

float TextList::getListHeight() const
{
    float height = space_y;
    height += (text_size + space_y)*getNumList();
    return height;
}

float TextList::getAvailableScroll() const
{
    float availableScroll = 0;
    availableScroll += getListHeight();
    availableScroll -= getRect().height;
    
    if(availableScroll < 0)
        availableScroll = 0;
    
    return availableScroll;
}

float TextList::getItemPositionY(int id) const
{
    float pos_y = 0;
    pos_y += space_y;
    pos_y += (text_size+space_y)*id;
    pos_y -= shift_y;
    
    return pos_y;
}

void TextList::update(EventHandler &e)
{
    if(isActive() == false)
        return;
        
    update_scroll(e);
    update_detect_click(e);
}

void TextList::draw(sf::RenderTarget &target)
{
    if(isActive() == false)
        return;
    
    sf::RenderTexture renderResult;
    renderResult.create( getRect().width , getRect().height );
    renderResult.clear();
    
    float tempx = getPosition().x;
    float tempy = getPosition().y;
    setPosition(0, 0);
    
    SpriteObject::draw(renderResult);
    
    setPosition(tempx, tempy);
    
    for(int i = 0 ; i < string_list.size() ; i++)
    {
        string text = string_list[i];
        TextObject item ("" , RenderLayer::PanelElementLayer , text);
        item.setSize(text_size);
        
        float x = space_x;
        float y = getItemPositionY( i );
        sf::FloatRect globalRect( getPosition().x + x , getPosition().y + y , item.getRect().width , item.getRect().height );
        
        if(globalRect.contains(WindowHelper::getMousePosition(window)))
            x += 5;
        
        item.setPosition(x, y);
        
        item.draw(renderResult);
    }
    
    renderResult.display();
    sf::Sprite temp( renderResult.getTexture() );
    temp.setPosition(getPosition().x, getPosition().y);
    
    target.draw(temp);
}

void TextList::update_scroll(EventHandler& e)
{
    if(e.cursorOn(this) == false)
        return;
    
    float top = getRect().top;
    float height = getRect().height;
    float bottom = top + height;
    
    float mouse_y = WindowHelper::getMousePosition(window).y;
    float ratio = (mouse_y - top)/height;
    
    float speed_scroll = 0;
    float max_speed = 15;
    
    if( ratio > 0.7 )
        speed_scroll = (ratio-0.7)/0.3*max_speed;
    else if( ratio < 0.3 )
        speed_scroll = -(0.3-ratio)/0.3*max_speed;
        
    scroll(speed_scroll);
}

void TextList::update_detect_click(EventHandler &e)
{
    if(e.gotClickOn(this) == false)
        return;
    
    selected_item = "";
    
    for(int i = 0 ; i < getNumList() ; ++i)
    {
        sf::FloatRect item_rect;
        item_rect.top = getPosition().y + getItemPositionY(i);
        item_rect.left = getPosition().x + space_x;
        item_rect.width = 500;
        item_rect.height = text_size;
        
        if(item_rect.contains(WindowHelper::getMousePosition(window)))
        {
            selected_item = string_list[i];
            return;
        }
    }
}
