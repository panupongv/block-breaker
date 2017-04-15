#include "WorkSpace.hpp"
#include "ResourcePath.hpp"

using namespace std;

WorkSpace::WorkSpace(Scene& scene,sf::RenderWindow& window)
: scene(scene),window(window)
{
    background = new SpriteObject
    (
        "work space bg",
     RenderLayer::EditingSpaceBackgroundLayer,
     "editor-spacce-background.png"
    );
    
    background->setColor(sf::Color(0,0,0,120));
    
    this->draft_block = new DraftBlock
    (
     "brick.png",
     window
     );
    
    scene.addObject(background);
    scene.addObject(draft_block);
}

void WorkSpace::update(EventHandler &e)
{
    update_overall(e);
}

UpdateOperation WorkSpace::getUpdateOperation() const
{
    return operation;
}

DraftBlock& WorkSpace::getDraftBlock()
{
    return *draft_block;
}

void WorkSpace::update_overall(EventHandler &e)
{
    
}

void WorkSpace::change_draft_block( const BlockType& type, const sf::Color& color )
{
    DraftBlock* new_draft_block = new DraftBlock(texture_name_of_type(type) ,window);
    new_draft_block->setColor(color);
    swap_new_draft_block(new_draft_block);
}

void WorkSpace::swap_new_draft_block(DraftBlock *new_draft_block)
{
    scene.removeObject(draft_block);
    this->draft_block = new_draft_block;
    scene.addObject(this->draft_block);
}

