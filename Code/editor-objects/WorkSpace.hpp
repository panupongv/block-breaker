#pragma once
#include "Scene.hpp"
#include "TextObject.hpp"
#include "SpriteObject.hpp"
#include "OptionPanel.hpp"

class WorkSpace
{
public:
    WorkSpace(Scene& scene);
    void update(EventHandler& e);
    UpdateOperation getUpdateOperation( ) const;
    
private:
    void update_overall(EventHandler& e);
    
private:
    const int block_size_x = 50;
    const int block_size_y = 18;
    
    UpdateOperation operation;
    
    SpriteObject* background;
    std::vector<TextObject*> buttons;
    std::vector<BaseObject*> elements;
};
