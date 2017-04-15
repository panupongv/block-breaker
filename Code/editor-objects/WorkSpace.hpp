#pragma once
#include "Scene.hpp"
#include "TextObject.hpp"
#include "SpriteObject.hpp"
#include "OptionPanel.hpp"
#include "DraftBlock.hpp"
#include "EditingBlock.hpp"

class WorkSpace
{
public:
    WorkSpace(Scene& scene,sf::RenderWindow& window);
    void update(EventHandler& e);
    UpdateOperation getUpdateOperation( ) const;
    DraftBlock& getDraftBlock();
    void change_draft_block( const BlockType& type, const sf::Color& color );
    
private:
    void update_overall(EventHandler& e);
    void update_click( EventHandler& e );
    void swap_new_draft_block(DraftBlock* new_draft_block);
    bool is_empty_at( sf::Vector2i grid );
    bool has_selecting_blocks() const;
    bool deselect_all_blocks();
    EditingBlock* block_at( sf::Vector2i grid );
    void deselect_block_at( sf::Vector2i grid );
    void select_block_at( sf::Vector2i grid );
    bool block_selected_at( sf::Vector2i grid );
    void assert_empty_at( sf::Vector2i grid );
    std::vector<EditingBlock*> get_selecting_block() const;
    void remove_block_at( sf::Vector2i grid );
    bool more_than_one_selecting() const;
    
private:
    const int block_size_x = 50;
    const int block_size_y = 18;
    
    UpdateOperation operation;
    
    SpriteObject* background;
    DraftBlock* draft_block;
    std::vector<EditingBlock*> blocks;
    std::vector<TextObject*> buttons;
    std::vector<BaseObject*> elements;
    
    Scene& scene;
    sf::RenderWindow& window;
};
