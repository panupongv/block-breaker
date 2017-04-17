#include "OptionPanel.hpp"
#include "WindowHelper.hpp"
#include "DirectoryReader.hpp"
#include "FileNameUtility.hpp"
#include "ResourcePath.hpp"

using namespace std;

OptionPanel::OptionPanel(Scene& scene , sf::RenderWindow& window)
	:
	operation(None)
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
        
        status = new TextObject
        (
            "status text",
             RenderLayer::PanelElementLayer,
             "[STATUS]\n\nplease enter file name"
        );
        status->setColor(sf::Color::White);
        
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
        
        palatte = new ColorPalatte
        (
            620,
            155,
            300,
            100,
            scene
        );
        
        block_buttons.push_back(new BlockTemplateButton(
            "normal block button",
            RenderLayer::PanelElementLayer,
            BlockType::normal
        ));
        
        block_buttons.push_back(new BlockTemplateButton(
            "breakable block button",
            RenderLayer::PanelElementLayer,
            BlockType::breakable
        ));
        
        block_buttons.push_back(new BlockTemplateButton(
            "item block button",
            RenderLayer::PanelElementLayer,
            BlockType::item
        ));
    }
    
    //Size Objects
    {
        input_field->setTextSize(16);
        
        status->setSize(char_size/1.5);
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
    status->setPosition(610, 80);
    for(int i = 0 ; i < block_buttons.size() ; ++i)
        block_buttons[i]->setPosition(650, 15 + (10+36)*i );

    scene.addObject(background);
    
    for(int i = 0 ; i < block_buttons.size() ; ++i)
        collectElement(block_buttons[i], scene);
    collectElement(input_field, scene);
    collectElement(list , scene);
    collectElement(status, scene);
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

sf::Color OptionPanel::getSelectedColor() const
{
    return selected_color;
}

BlockType OptionPanel::getSelectedType() const
{
    return selected_type;
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
    palatte->disable();
    
    for(int i = 0 ; i < elements.size() ; i++)
        elements[i]->disable();
}

void OptionPanel::changeModeTo(OptionMode mode)
{
    disableAll();
    
    this->prevMode = this->mode;
    this->mode = mode;
    
    switch (mode)
    {
        case Load:
            input_field->enable();
            input_field->clearText();
            list->enable();
            button_new->enable();
            button_exit->enable();
            
            set_button_position(button_new, 1);
            set_button_position(button_exit, 0);
            if(this->prevMode == Edit)
            {
                button_exit->disable();
                button_cancel->enable();
                
                set_button_position(button_cancel, 0);
            }
            break;
            
        case Edit:
            for(int i = 0 ; i < block_buttons.size() ; ++i)
                block_buttons[i]->enable();
            
            palatte->enable();
            button_new->enable();
            button_load->enable();
            button_save->enable();
            
            set_button_position(button_new, 2);
            set_button_position(button_load, 1);
            set_button_position(button_save, 0);
            break;
            
        case Save:
            input_field->enable();
            input_field->setText(file_name.substr(0,file_name.size()-8));
            status->enable();
            button_cancel->enable();
            button_confirm_save->disable();
            button_replace->disable();
            
            set_button_position(button_confirm_save, 1);
            set_button_position(button_replace, 1);
            set_button_position(button_cancel, 0);
            break;
            
        default:
            break;
    }
}

void OptionPanel::set_button_position(BaseObject* button, int id_y)
{
    float x = left_edge;
    float y = WindowHelper::res_y - char_size*2 - char_size*1.6*id_y;
    
    button->setPosition(x, y);
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
    BBStageFileFinder finder(stagePath());
    vector<string> files = finder.searchFileNames(search_string);
    list->setStringList(files);
    
    if(e.gotClickOn(list))
    {
        //if click on list then load stage
        
        string selected_item = list->getSelectedItem();
        
        if(selected_item != "")
        {
            operation = LoadStage;
            changeModeTo(Edit);
            file_name = selected_item;
            return;
        }
    }
    
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
}

void OptionPanel::update_in_edit_mode(EventHandler &e)
{
    for(int i = 0 ; i < block_buttons.size() ; ++i)
    {
        if(e.gotClickOn(block_buttons[i]))
        {
            for(int j = 0 ; j < block_buttons.size() ; ++j)
                block_buttons[j]->deselect();
            
            block_buttons[i]->select();
            
            selected_type = block_buttons[i]->getType();
            operation = ChangeType;
            
            cout << "change block mode" << endl;
        }
        
    }
    
    palatte->update(e);
    
    if(palatte->gotClick(e))
    {
        cout << "change color :\n";
        selected_color = palatte->getSelectedColor();
        
        for(int i = 0 ; i < block_buttons.size() ; ++i)
        {
            block_buttons[i]->setColor(selected_color);
        }

        operation = ChangeColor;
        return;
    }
    
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
    string entered_file_name = input_field->getText() + ".bbstage";
    
    if(input_field->getText().empty())
    {
        status->setText("[STATUS]\n\nplease enter file name");
        status->setColor(sf::Color::White);
        
        button_confirm_save->disable();
        button_replace->disable();
    }
    else
    {
        FileNameUtility util;
        bool already_exist = util.file_exist(stagePath() + entered_file_name);
        
        if(already_exist)
        {
            status->setText("[STATUS]\n\nwarning, file name existed\nbut you can replace file");
            status->setColor(sf::Color::Red);
            
            button_confirm_save->disable();
            button_replace->enable();
        }
        else
        {
            status->setText("[STATUS]\n\nfile name available\nclick save button to\nprocess saving file");
            status->setColor(sf::Color::Green);
            
            button_confirm_save->enable();
            button_replace->disable();
        }
    }
    
    if(e.gotClickOn(button_confirm_save))
    {
        changeModeTo(Edit);
        operation = SaveFileOperation;
        update_file_name(entered_file_name);
        return;
    }
    
    if (e.gotClickOn(button_replace))
    {
        changeModeTo(Edit);
        operation = ReplaceFileOperation;
        update_file_name(entered_file_name);
        return;
    }
    
    if (e.gotClickOn(button_cancel))
    {
        changeModeTo(Edit);
        return;
    }
}

void OptionPanel::update_file_name(string new_file_name)
{
    this->file_name = new_file_name;
}

