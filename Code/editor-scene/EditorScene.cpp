#include "EditorScene.hpp"
#include "EventHandler.hpp"

#include <iostream>

using namespace std;

EditorScene::EditorScene( sf::RenderWindow& window ) : Scene("editor",window),panel(*this) { };

void EditorScene::update(EventHandler& eHandler)
{
    Scene::update(eHandler);
    
    //implement update here
//    if(eHandler.gotClickOn(stage_title))
//    {
//        cout << "drag on text : " << rand()%100 << endl;
//        stage_title->disable();
//    }
    
//    if(eHandler.cursorOn(background))
//        cout << "cursor on bg : " << rand()%1000 << endl;
    
    panel.update(eHandler);
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
    this->stage_title->setColor(sf::Color::White);
    this->stage_title->setSize( 30 );
    
    this->background = new SpriteObject
    (
        "editor background" ,
        RenderLayer::BackgroundLayer ,
        "editor-background.png"
    );
    
    
    this->draft_block = new DraftBlock
    (
        "brick.png",
        this->getWindow()
    );
    
    this->addObject(this->background);
    this->addObject(this->draft_block);
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

