#pragma once
#include "Scene.hpp"
#include "TextObject.hpp"
#include "SpriteObject.hpp"
#include "OptionPanel.hpp"
#include "DraftBlock.hpp"

class WorkSpace
{
public:
    WorkSpace(Scene& scene,sf::RenderWindow& window);
    void update(EventHandler& e);
    UpdateOperation getUpdateOperation( ) const;
    
private:
    void update_overall(EventHandler& e);
    
private:
    const int block_size_x = 50;
    const int block_size_y = 18;
    
    UpdateOperation operation;
    
    SpriteObject* background;
    DraftBlock* draft_block;
    std::vector<TextObject*> buttons;
    std::vector<BaseObject*> elements;
};
