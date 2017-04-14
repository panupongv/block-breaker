#include "EditorScene.hpp"
#include "EventHandler.hpp"

#include <iostream>

using namespace std;

EditorScene::EditorScene( sf::RenderWindow& window ) : Scene("editor",window),panel(*this,window),space(*this,window) { };

void EditorScene::update(EventHandler& eHandler)
{
    Scene::update(eHandler);
    
//    cout << eHandler.gotKey(sf::Keyboard::E) << endl;
    //implement update here
//    if(eHandler.gotClickOn(stage_title))
//    {
//        cout << "drag on text : " << rand()%100 << endl;
//        stage_title->disable();
//    }
    
//    if(eHandler.cursorOn(background))
//        cout << "cursor on bg : " << rand()%1000 << endl;
//    static string s;
//    if(eHandler.getString()[0] == 8)
//        s.erase(s.size()-1);
//    else
//        s += eHandler.getString();
//    if(eHandler.getString().empty() == false)
//        cout << s << endl;
    
    panel.update(eHandler);
    UpdateOperation panelOperation = panel.getUpdateOperation();
    
    if(panelOperation == Exit)
    {
        flagEnded();
        setNextScene(NULL);
        return;
    }
    
    space.update(eHandler);
    UpdateOperation spaceOperation = space.getUpdateOperation();
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

