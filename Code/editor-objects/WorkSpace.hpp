/*
 group-objects/WorkSpace.hpp
*/

#pragma once
#include "Scene.hpp"
#include "TextObject.hpp"
#include "SpriteObject.hpp"
#include "OptionPanel.hpp"
#include "DraftBlock.hpp"
#include "EditingBlock.hpp"
#include "StageData.hpp"

class WorkSpace
{
public:
    WorkSpace(Scene& scene,sf::RenderWindow& window);
    void update(EventHandler& e);
    UpdateOperation getUpdateOperation( ) const;
    DraftBlock& getDraftBlock();
    void change_draft_block( const BlockType& type, const sf::Color& color );
    void clear_all();
    void load_from_data(StageData& stage_data);
    void save_stage_as(std::string file_name,bool replace = false) const;
    void set_editable(bool editable);
    bool is_editable() const;
    
private:
    void update_overall(EventHandler& e);
    void update_cursor(EventHandler& e);
    void update_click( EventHandler& e );
    void update_key( EventHandler& e );
    void swap_new_draft_block(DraftBlock* new_draft_block);
    bool is_empty_at( sf::Vector2i grid );
    bool has_selecting_blocks() const;
    void deselect_all_blocks();
    void select_all_blocks();
    EditingBlock* block_at( sf::Vector2i grid );
    void deselect_block_at( sf::Vector2i grid );
    void select_block_at( sf::Vector2i grid );
    bool block_selected_at( sf::Vector2i grid );
    void assert_empty_at( sf::Vector2i grid );
    std::vector<EditingBlock*> get_selecting_block() const;
    void remove_block_at( sf::Vector2i grid );
    bool more_than_one_selecting() const;
    void create_block( DraftBlock* draft_block , sf::Vector2i grid );
    void load_block( BlockData data );
    bool selecting_block_can_move ( sf::Vector2i direction);
    bool selecting_pin_can_move ( sf::Vector2i direction );
    void move_selecting_block ( sf::Vector2i direction );
    void move_selecting_pin ( sf::Vector2i direction );
    bool out_of_bound ( sf::Vector2i grid );
    
private:
    const int block_size_x = 50;
    const int block_size_y = 18;
    
    bool editable = false;
    UpdateOperation operation;
    
    SpriteObject* background;
    DraftBlock* draft_block;
    std::vector<EditingBlock*> blocks;
    std::vector<TextObject*> buttons;
    std::vector<BaseObject*> elements;
    
    Scene& scene;
    sf::RenderWindow& window;
};
