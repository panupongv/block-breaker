#pragma once
#include "SpriteObject.hpp"
/*
 editor-objects/TextList.hpp
*/

#include "TextObject.hpp"

class TextList : public SpriteObject
{
public:
    TextList( std::string name , RenderLayer layer , std::string texture_name , sf::RenderWindow& window);
    
    void setStringList( std::vector<std::string> list );
    void setSpaceX( int space_x );
    void setSpaceY( int space_y );
    
    std::string getSelectedItem() const;
    int getSpaceX() const;
    int getSpaceY() const;
    int getTextSize() const;
    int getNumList() const;
    float getListHeight() const;
    void scroll ( float y );
    
    //polymorphism
    virtual void update( EventHandler& e );
    virtual void draw ( sf::RenderTarget& target );
    
private:
    float getAvailableScroll ( ) const;
    float getItemPositionY( int id ) const;
    void update_scroll(EventHandler& e);
    void update_detect_click(EventHandler& e);
    
private:
    sf::RenderWindow& window;
    std::vector<std::string> string_list;
    float shift_y = 0;
    int text_size = 20 ;
    int space_y = 10;
    int space_x = 10;
    
    std::string selected_item = "";

};
