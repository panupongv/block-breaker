#include "EditorScene.hpp"
#include "EventHandler.hpp"

#include <iostream>

using namespace std;

EditorScene::EditorScene( sf::RenderWindow& window ) : Scene("editor",window),panel(*this,window),space(*this,window) { };

void EditorScene::update(EventHandler& eHandler)
{
    Scene::update(eHandler);
    panel.update(eHandler);
    space.update(eHandler);
    
    UpdateOperation panelOperation = panel.getUpdateOperation();
    UpdateOperation spaceOperation = space.getUpdateOperation();
    
    if(panelOperation == Exit)
    {
        flagEnded();
        setNextScene(NULL);
        return;
    }
    else if( panelOperation == LoadStage)
    {
        load_stage(panel.getFileName());
        return;
    }
    else if(panelOperation == ChangeType || panelOperation == ChangeColor )
    {
        BlockType selected_type = panel.getSelectedType();
        sf::Color selected_color = panel.getSelectedColor();
        space.change_draft_block(selected_type, selected_color);
    }
}

void EditorScene::draw()
{
    Scene::draw();
}

void EditorScene::init()
{
    this->stage_title = new TextObject
    (
        "stage text",
        RenderLayer::TitleLayer,
        "stage-title.bbstage"
    );
    this->stage_title->setPosition(300, 20 , PositioningMode::Center );
    this->stage_title->setColor(sf::Color::Black);
    this->stage_title->setSize( 30 );
    
    this->background = new SpriteObject
    (
        "editor background" ,
        RenderLayer::BackgroundLayer ,
        "editor-background.png"
    );
    
    
    this->addObject(this->background);
    this->addObject(this->stage_title);
}

void EditorScene::begin()
{
    Scene::begin();
    
    //todo;
}

void EditorScene::end()
{
    //todo;
}

void EditorScene::load_stage(std::string file_name)
{
    cout << "need load stage implementation" << endl;
    cout << "file : " << file_name << endl;
}

