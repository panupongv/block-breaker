#include "WorkSpace.hpp"

WorkSpace::WorkSpace(Scene& scene)
{
    background = new SpriteObject
    (
        "work space bg",
     RenderLayer::EditingSpaceBackgroundLayer,
     "editor-spacce-background.png"
    );
    
    background->setColor(sf::Color(0,0,0,120));
    
    scene.addObject(background);
}

void WorkSpace::update(EventHandler &e)
{
    update_overall(e);
}

UpdateOperation WorkSpace::getUpdateOperation() const
{
    return operation;
}

void WorkSpace::update_overall(EventHandler &e)
{
    
}
