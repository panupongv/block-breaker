#include "WorkSpace.hpp"
#include "ResourcePath.hpp"
#include "WindowHelper.hpp"
#include "helperfunc.hpp"

using namespace std;

WorkSpace::WorkSpace(Scene& scene,sf::RenderWindow& window)
: scene(scene),window(window)
{
    background = new SpriteObject
    (
        "work space bg",
     RenderLayer::EditingSpaceBackgroundLayer,
     "editor-spacce-background.png"
    );
    
    background->setColor(sf::Color(0,0,0,120));
    
    this->draft_block = new DraftBlock
    (
     BlockType::breakable,
     sf::Color::White,
     window
     );
    
    scene.addObject(background);
    scene.addObject(draft_block);
}

void WorkSpace::update(EventHandler &e)
{
    if(is_editable() == false)
        return;
    update_overall(e);
    update_click(e);
}

UpdateOperation WorkSpace::getUpdateOperation() const
{
    return operation;
}

DraftBlock& WorkSpace::getDraftBlock()
{
    return *draft_block;
}

void WorkSpace::update_overall(EventHandler &e)
{
    
}

void WorkSpace::update_click(EventHandler &e)
{
    bool no_click = not e.gotClickOn(background);
    
    if(no_click)
        return;
    
    sf::Vector2f mouse_pos = WindowHelper::getMousePosition(window);
    sf::Vector2i click_grid = helper::grid_of_pos(mouse_pos);
    
    bool out_x = click_grid.x < 0 || click_grid.x > helper::grid_num_x;
    bool out_y = click_grid.y < 0 || click_grid.y > helper::grid_num_y;
    bool out_bound = out_x || out_y;
    
    if( out_bound )
        return;
    
    if( is_empty_at(click_grid) )
    {
        if( has_selecting_blocks() )
            deselect_all_blocks();
        else
            create_block(draft_block, click_grid);
    }
    else //click a block
    {
        bool ctrl_hold = e.gotKeyHold(sf::Keyboard::LControl);
        bool cmd_hold = e.gotKeyHold(sf::Keyboard::RSystem);
        
        if( ctrl_hold || cmd_hold )//hold control
        {
            EditingBlock* block = block_at(click_grid);
            
            if(block_selected_at(click_grid))
                deselect_block_at(click_grid);
            else
                select_block_at(click_grid);
        }
        else
        {
            if(block_selected_at(click_grid))// fix herererhjasdfkjaslkdjfkaljdlskfjlkasdjfadfasdlkfjdkjkjkjkjkjkj
                remove_block_at(click_grid);
            else
                select_block_at(click_grid);
        }
    }
    
    
}

void WorkSpace::change_draft_block( const BlockType& type, const sf::Color& color )
{
    DraftBlock* new_draft_block = new DraftBlock(type , color ,window);
    swap_new_draft_block(new_draft_block);
}

void WorkSpace::clear_all()
{
    for(int i = 0 ; i < blocks.size() ; ++i)
        scene.removeObject(blocks[i]);
    
    blocks.clear();
}

void WorkSpace::load_from_data(StageData& data)
{
    clear_all();
    data.load();
    vector<BlockData> block_datas = data.getBlocksData();
    for(int i = 0 ; i < block_datas.size() ; ++i)
    {
        load_block(block_datas[i]);
    }
}

void WorkSpace::save_stage_as(string file_name , bool replace ) const
{
    StageData stage_file(file_name);
    
    for(int i = 0 ; i < blocks.size() ; ++i)
        stage_file.addBlock(*blocks[i]);
    
    cout <<
    stage_file.save(replace) << endl;
}

void WorkSpace::set_editable(bool editable)
{
    this->editable = editable;
}

bool WorkSpace::is_editable() const
{
    return this->editable;
}


void WorkSpace::swap_new_draft_block(DraftBlock *new_draft_block)
{
    scene.removeObject(draft_block);
    this->draft_block = new_draft_block;
    scene.addObject(this->draft_block);
}

bool WorkSpace::is_empty_at(sf::Vector2i grid)
{
    for(int i = 0 ; i < blocks.size() ; ++i )
    {
        sf::Vector2i block_grid = blocks[i]->getStartGrid();
        
        if(block_grid == grid)
            return false;
    }
    
    return true;
}

bool WorkSpace::has_selecting_blocks() const
{
    return get_selecting_block().size() > 0;
}

bool WorkSpace::deselect_all_blocks()
{
    vector<EditingBlock*> selecting_blocks = get_selecting_block();
    for(int i = 0 ; i < selecting_blocks.size() ; i++)
    {
        selecting_blocks[i]->deselect();
    }
}

EditingBlock* WorkSpace::block_at(sf::Vector2i grid)
{
    for(int i = 0 ; i < blocks.size() ; ++i)
    {
        sf::Vector2i block_grid = blocks[i]->getStartGrid();
        if(block_grid == grid)
        {
            return blocks[i];
        }
    }
}

void WorkSpace::select_block_at(sf::Vector2i grid)
{
    assert_empty_at(grid);
    block_at(grid)->select();
}

void WorkSpace::deselect_block_at(sf::Vector2i grid)
{
    assert_empty_at(grid);
    block_at(grid)->deselect();
}

bool WorkSpace::block_selected_at(sf::Vector2i grid)
{
    assert_empty_at(grid);
    return block_at(grid)->isSelected();
}

void WorkSpace::assert_empty_at(sf::Vector2i grid)
{
    if( is_empty_at(grid) )
        throw invalid_argument("no any block at grid given");
}

vector<EditingBlock*> WorkSpace::get_selecting_block() const
{
    std::vector<EditingBlock*> selecting_blocks;
    
    for(int i = 0 ; i < blocks.size() ; ++i)
    {
        if(blocks[i]->isSelected())
            selecting_blocks.push_back(blocks[i]);
    }
    
    return selecting_blocks;
}

void WorkSpace::remove_block_at(sf::Vector2i grid)
{
    EditingBlock* block = block_at(grid);
    
    for(int i = 0 ; i < blocks.size() ;++i )
    {
        if(blocks[i] == block)
        {
            blocks.erase(blocks.begin() + i);
            break;
        }
    }
    
    scene.removeObject(block);
}

bool WorkSpace::more_than_one_selecting() const
{
    vector<EditingBlock*> selecting_blocks = get_selecting_block();
    return selecting_blocks.size() > 1;
}

void WorkSpace::create_block(DraftBlock *draft_block, sf::Vector2i grid)
{
    EditingBlock* new_block = new EditingBlock(*draft_block , grid , grid , scene );
    blocks.push_back( new_block );
    scene.addObject( new_block );
}

void WorkSpace::load_block(BlockData data)
{
    BlockType type = data.getType();
    sf::Color color = data.getColor();
    sf::Vector2i start = data.getStartGrid();
    sf::Vector2i move = data.getMovement_single();
    
    DraftBlock temp_draft( type , color , window );
    EditingBlock* new_block = new EditingBlock(temp_draft , start , move , scene );
    blocks.push_back( new_block );
    scene.addObject( new_block );
}

