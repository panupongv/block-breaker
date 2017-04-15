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
        
    static int speed_scroll = 0;
    static int count = 0;
    if(e.cursorOn(this))
        if(e.gotKey(sf::Keyboard::Up))
        {
            speed_scroll += 1;
            count = 0;
        }
        else if( e.gotKey(sf::Keyboard::Down))
        {
            speed_scroll -= 1;
            count = 0;
        }
        else
        {
            count++;
            if(count >= 10)
            {
                speed_scroll = 0;
            }
        }
    
    scroll(speed_scroll);
        
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



