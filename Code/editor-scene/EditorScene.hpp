#pragma once

#include <string>
#include <vector>
#include "Scene.hpp"
#include "TextObject.hpp"
#include "SpriteObject.hpp"
#include "DraftBlock.hpp"
#include "EventHandler.hpp"

class EditorScene : public Scene
{
public:
    EditorScene( sf::RenderWindow& window );
    virtual void update(EventHandler& eHandler);
    virtual void draw();
    
protected:
    virtual void begin();
    virtual void end();
    virtual void init();
    
private:
    SpriteObject* background;
    SpriteObject* option_panel;
    TextObject* stage_title;
    DraftBlock* draft_block;
};
