#include "EditorScene.hpp"
#include <iostream>

using namespace std;

EditorScene::EditorScene() : Scene("editor") { };

void EditorScene::update(sf::Event &event)
{
    Scene::update(event);
    
    //implement update here
//    brick->move(10, 10);
}

void EditorScene::draw(sf::RenderWindow &window)
{
    Scene::draw(window);
}

void EditorScene::init()
{
    this->stage_title = new TextObject
    (
        "stage text",
        RenderLayer::Foreground,
        "stage-title.bbstage"
    );
    this->stage_title->setPosition(300, 20 , PositioningMode::Center );
    this->stage_title->setColor(sf::Color::White);
    this->stage_title->setSize( 30 );
    
    this->background = new SpriteObject
    (
        "editor background" ,
        RenderLayer::Background ,
        "editor-background.png"
    );
    
    this->option_panel = new SpriteObject
    (
        "panel background" ,
        RenderLayer::Background ,
        "editor-panel-background.png"
    );
    this->option_panel->setPosition( 600, 0 );
    
    this->addObject(this->background);
    this->addObject(this->option_panel);
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

