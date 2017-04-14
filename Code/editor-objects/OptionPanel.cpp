#include "OptionPanel.hpp"
#include "WindowHelper.hpp"
#include "DirectoryReader.hpp"

#include <iostream>

using namespace std;

OptionPanel::OptionPanel(Scene& scene , sf::RenderWindow& window)
{
    //Create Objects
    {
        background = new SpriteObject
        (
            "panel bg",
            RenderLayer::PanelBackgroundLayer,
            "panel-bg.png"
        );
        
        input_field = new InputField
        (
            "file name input",
            RenderLayer::PanelElementLayer,
            "input-field.png"
        );
        input_field->setTextColor(sf::Color::White);
        
        list = new TextList
        (
            "file list",
             RenderLayer::PanelElementLayer,
             "file-list.png",
            window
        );
        
        button_new = new TextObject
        (
            "new button",
            RenderLayer::PanelElementLayer,
            "|  New Stage"
        );
        
        button_load = new TextObject
        (
            "load button",
             RenderLayer::PanelElementLayer,
             "|  Load Stage"
         );
        
        button_save = new TextObject
        (
            "save button",
            RenderLayer::PanelElementLayer,
            "|  Save Stage"
         );
        
        button_confirm_save = new TextObject
        (
        "confirm save button",
         RenderLayer::PanelElementLayer,
         "|  Save File"
        );
        
        button_replace = new TextObject
        (
        "replace button",
         RenderLayer::PanelElementLayer,
         "|  Replace File"
        );
        
        button_cancel = new TextObject
        (
            "cancel button",
         RenderLayer::PanelElementLayer,
         "|  Cancle"
         );
            
        button_exit = new TextObject
        (
            "exit button",
            RenderLayer::PanelElementLayer,
            "|  Exit  '_'"
        );
        
        
    }
    
    //Size Objects
    {
        input_field->setTextSize(15);
        
        button_new->setSize(char_size);
        button_load->setSize(char_size);
        button_save->setSize(char_size);
        button_confirm_save->setSize(char_size);
        button_replace->setSize(char_size);
        button_cancel->setSize(char_size);
        button_exit->setSize(char_size);
    }
    
    //Position Objects
    background->setPosition(600, 0);
    input_field->setPosition(610, 20);
    list->setPosition(610, 70);

    scene.addObject(background);
    
    collectElement(input_field, scene);
    collectElement(list , scene);
    collectButton(button_new,scene);
    collectButton(button_load,scene);
    collectButton(button_save,scene);
    collectButton(button_confirm_save,scene);
    collectButton(button_replace,scene);
    collectButton(button_cancel,scene);
    collectButton(button_exit, scene);
    
    changeModeTo(OptionMode::Load);
}

OptionMode OptionPanel::getCurrentMode() const
{
    return this->mode;
}

void OptionPanel::update(EventHandler& e)
{
    update_overall(e);
    
    switch (getCurrentMode())
    {
        case Load:
            update_in_load_mode(e);
            break;
            
        case Edit:
            update_in_edit_mode(e);
            break;
            
        case Save:
            update_in_save_mode(e);
            break;
            
        default:
            break;
    }
}

UpdateOperation OptionPanel::getUpdateOperation() const
{
    UpdateOperation temp = this->operation;
    return temp;
}

string OptionPanel::getFileName() const
{
    return file_name;
}

void OptionPanel::collectButton(TextObject *button , Scene& scene)
{
    buttons.push_back(button);
    elements.push_back(button);
    scene.addObject(button);
}

void OptionPanel::collectElement(BaseObject *element, Scene& scene)
{
    elements.push_back(element);
    scene.addObject(element);
}

void OptionPanel::disableAll()
{
    for(int i = 0 ; i < elements.size() ; i++)
    {
        elements[i]->disable();
    }
}

void OptionPanel::changeModeTo(OptionMode mode)
{
    disableAll();
    
    this->prevMode = this->mode;
    this->mode = mode;
    
    float x = left_edge;
    float y[5];
    for(int i = 0 ; i < 5 ; i++)
        y[i] = WindowHelper::res_y - char_size*2 - char_size*1.6*i;
    
    switch (mode)
    {
        case Load:
            input_field->enable();
            input_field->clearText();
            list->enable();
            button_new->enable();
            button_new->setPosition(x, y[1]);
            button_exit->enable();
            button_exit->setPosition(x, y[0]);
            if(this->prevMode == Edit)
            {
                button_exit->disable();
                button_cancel->enable();
                button_cancel->setPosition(x, y[0]);
            }
            break;
            
        case Edit:
            button_new->enable();
            button_load->enable();
            button_save->enable();
            button_new->setPosition(x, y[2]);
            button_load->setPosition(x, y[1]);
            button_save->setPosition(x, y[0]);
            break;
            
        case Save:
            input_field->enable();
            input_field->clearText();
            button_confirm_save->enable();
            button_replace->enable();
            button_cancel->enable();
            button_confirm_save->setPosition(x, y[2]);
            button_replace->setPosition(x, y[1]);
            button_cancel->setPosition(x, y[0]);
            break;
            
        default:
            break;
    }
}

void OptionPanel::update_overall(EventHandler &e)
{
    this->operation = None;
    
    for(int i = 0 ; i < buttons.size() ; ++i)
    {
        BaseObject& button = *buttons[i];
        
        if(e.cursorOn(button))
        {
            button.setPosition(left_edge+5, button.getPosition().y);
        }
        else
            button.setPosition(left_edge, button.getPosition().y);
    }
}

void OptionPanel::update_in_load_mode(EventHandler &e)
{
    string search_string = input_field->getText();
    BBStageFileFinder finder("stages");
    vector<string> files = finder.searchFileNames(search_string);
    list->setStringList(files);
    
    if(e.gotClickOn(button_new))
    {
        changeModeTo(Edit);
        operation = NewStage;
        return;
    }
    
    if(e.gotClickOn(button_cancel))
    {
        changeModeTo(Edit);
        return;
    }
    
    if(e.gotClickOn(button_exit))
    {
        operation = Exit;
        return;
    }
    
    //if click on list then load stage
}

void OptionPanel::update_in_edit_mode(EventHandler &e)
{
    if(e.gotClickOn(button_new))
    {
        operation = NewStage;
        return;
    }
    
    if(e.gotClickOn(button_save))
    {
        changeModeTo(Save);
        return;
    }
    
    if(e.gotClickOn(button_load))
    {
        changeModeTo(Load);
        return;
    }
}

void OptionPanel::update_in_save_mode(EventHandler &e)
{
    if(e.gotClickOn(button_confirm_save))
    {
        changeModeTo(Edit);
        operation = SaveFile;
        return;
    }
    
    if (e.gotClickOn(button_replace))
    {
        changeModeTo(Edit);
        operation = ReplaceFile;
        return;
    }
    
    if (e.gotClickOn(button_cancel))
    {
        changeModeTo(Edit);
        return;
    }
}

