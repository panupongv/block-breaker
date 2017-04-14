#pragma once
#include "SpriteObject.hpp"
#include "TextObject.hpp"
#include "Scene.hpp"
#include "EventHandler.hpp"

enum OptionMode { Load , Edit , Save };

enum PanelOperation { None, NewStage , LoadStage , SaveFile , ReplaceFile , Exit };

class OptionPanel
{
public:
    OptionPanel(Scene& scene);
    void update(EventHandler& eHandler);
    OptionMode getCurrentMode() const;
    PanelOperation getUpdateOperation( ) const;
    
private:
    void collectButton(TextObject* button,Scene& scene);
    void collectElement(BaseObject* element,Scene& scene);
    void disableAll();
    void changeModeTo(OptionMode mode);
    void update_overall(EventHandler& e);
    void update_in_load_mode(EventHandler& e);
    void update_in_edit_mode(EventHandler& e);
    void update_in_save_mode(EventHandler& e);
    
private:
    const int char_size = 25;
    const int left_edge = 615;
    
    std::string file_name;
    PanelOperation operation = PanelOperation::None;
    
    std::vector<TextObject*> buttons;
    std::vector<BaseObject*> elements;
    SpriteObject* background;
    OptionMode mode = OptionMode::Load;
    OptionMode prevMode = OptionMode::Load;
    
    TextObject* button_new;
    TextObject* button_load;
    TextObject* button_save;
    TextObject* button_confirm_save;
    TextObject* button_replace;
    TextObject* button_cancel;
    TextObject* button_exit;
    
    //InputField
    //Directory list
    
    /*
     load mode
     - file list
     - "new stage"
     - "load stage"
     */
    
    /*
     edit mode
     - "new stage"
     - "save stage"
     - "load stage"
     */
    
    /*
     save mode
     - input field ( type name )
     - "save file"
     - "replace file"
     - "cancel"
     */
};
