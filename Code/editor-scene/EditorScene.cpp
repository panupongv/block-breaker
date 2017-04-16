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
        stage_title->setText(panel.getFileName());
        space.set_editable(true);
    }
    else if(panelOperation == ChangeType || panelOperation == ChangeColor )
    {
        BlockType selected_type = panel.getSelectedType();
        sf::Color selected_color = panel.getSelectedColor();
        
        space.change_draft_block(selected_type, selected_color);
    }
    else if(panelOperation == NewStage)
    {
        space.clear_all();
        stage_title->setText("untitled.bbstage");
        space.set_editable(true);
    }
    else if(panelOperation == SaveFileOperation )
    {
        save_stage(panel.getFileName());
        stage_title->setText(panel.getFileName());
    }
    else if ( panelOperation == ReplaceFileOperation )
    {
        save_stage(panel.getFileName() , true);
        stage_title->setText(panel.getFileName());
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
        "title.bbstage"
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
    
    StageData stage_data("title.bbstage");
    space.load_from_data(stage_data);
    space.set_editable(false);
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
    cout << "load from " << file_name << endl;
    StageData data(file_name);
    space.load_from_data(data);
}

void EditorScene::save_stage(std::string file_name , bool replace )
{
    space.save_stage_as(file_name , replace);
}

