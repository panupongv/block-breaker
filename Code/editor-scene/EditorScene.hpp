#pragma once

#include <string>
#include <vector>
#include "Scene.hpp"
#include "TextObject.hpp"
#include "SpriteObject.hpp"
#include "DraftBlock.hpp"
#include "EventHandler.hpp"
#include "OptionPanel.hpp"
#include "WorkSpace.hpp"

class EditorScene : public Scene
{
public:
    EditorScene( sf::RenderWindow& window );
    virtual void update(EventHandler& eHandler);
    virtual void draw();
	//virtual ~EditorScene() = 0;

protected:
    virtual void begin();
    virtual void end();
    virtual void init();
    
private:
    void load_stage( std::string file_name );
    void save_stage( std::string file_name , bool replace = false);
    void set_title( std::string text );
    
private:
    OptionPanel panel;
    WorkSpace space;
    SpriteObject* background;
    TextObject* stage_title;
    

};
