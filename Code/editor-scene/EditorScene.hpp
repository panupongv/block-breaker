#pragma once

#include <string>
#include <vector>
#include "Scene.hpp"

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
//    void createSelectionBlock();
//    void createEditableBlock();
//    void createDraftBlock();
    //and more
    
};