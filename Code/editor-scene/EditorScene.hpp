#pragma once

#include <string>
#include <vector>
#include "Scene.hpp"
#include "TextObject.hpp"
#include "SpriteObject.hpp"

class EditorScene : public Scene
{
public:
    EditorScene();
    virtual void update(sf::Event& event);
    virtual void draw(sf::RenderWindow& window);
    
protected:
    virtual void begin();
    virtual void end();
    virtual void init();
    
private:
    SpriteObject* background;
    SpriteObject* option_panel;
    TextObject* stage_title;
    
//    void createSelectionBlock();
//    void createEditableBlock();
//    void createDraftBlock();
    //and more
    
};
