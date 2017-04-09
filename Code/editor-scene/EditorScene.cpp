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
    this->stage_title = new TextObject("stage text",RenderLayer::Foreground,"dummy text",100,100);
    this->stage_title->setColor(sf::Color::Blue);
    this->stage_title->setSize( 60 );
    
//    this->background = new SpriteObject
//    (
//     "editor background" ,
//     RenderLayer::Background,
//     );
    
//    this->addObject(this->background);
//    this->addObject(this->option_panel);
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

