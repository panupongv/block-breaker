#include "Game.hpp"

Game::Game(sf::RenderWindow * window)
	:
	window(window),
	finished(false),
	endless(true),
	frame_passed(0),
	current_color(0),
	lives(1)
{
	srand(time(NULL));
	if (!setup())
	{
		std::cout << "Game setup failed" << std::endl;
	}
	
	for (int j = -1; j < 8; j++)
	{
		generateRow(upper_bound + j * Block::block_size_y);
	}
	
}

Game::Game(sf::RenderWindow * window, std::string file_name)
	:
	window(window),
	finished(false),
	endless(false),
	lives(1)
{
	srand(time(NULL));
	StageData stage_data(file_name);
	if (!stage_data.load())
	{
		std::cout << "No map found" << std::endl;
	}

	if (!setup())
	{
		std::cout << "Game setup failed" << std::endl;
	}

	std::vector<BlockData> block_datas = stage_data.getBlocksData();
	block_num = block_datas.size();
	for (int i = 0; i < block_num; i++)
	{
		//Block * temp_block = new Block(block_datas[i]);
		Block* new_block = BlockGenerator::create(block_datas[i], false);
		new_block->move(left_bound, upper_bound);
		block_list.push_back(new_block);
		sprite_list.push_back(new_block);
		//std::cout << "Brick[" << i << "] at " << block_datas[i].getStartGrid().x << ", " << block_datas[i].getStartGrid().y << std::endl;
	}
}

Game::~Game()
{
	const int sprite_num = sprite_list.size();
	for (int i = 0; i < sprite_num; i++)
		delete sprite_list[i];
	std::cout << "Freed " << sprite_num << " sprites" << std::endl;
}

void Game::run()
{
	while (!finished && window->isOpen())
	{
		draw_sprites();
		update_sprites();
		event_input();
		frame_passed++;
		if (frame_passed == static_cast<int>(Block::block_size_y / Block::move_speed) * Block::frame_to_move)
			generateRow(upper_bound - Block::block_size_y);
	}
	std::cout << "Game ended" << std::endl;
}

void Game::add(Ball * ball)
{
	ball_list.push_back(ball);
	sprite_list.push_back(ball);
	std::cout << ball->left() << ", " << ball->top() << std::endl;
}

void Game::add(Item * item)
{
	item_list.push_back(item);
	sprite_list.push_back(item);

}

void Game::pop(Ball * ball)
{
	for (int i = 0; i < sprite_list.size(); i++)
	{
		if (sprite_list[i] == ball)
		{
			sprite_list.erase(sprite_list.begin() + i);
			break;
		}
	}

	//const int block_num = block_list.size();
	for (int i = 0; i < ball_list.size(); i++)
	{
		if (ball_list[i] == ball)
		{
			delete ball;
			ball = NULL;
			ball_list.erase(ball_list.begin() + i);
			//std::cout << "POP BLOCK" << std::endl;
			break;
		}
	}
	if (ball_list.empty())
	{
		lives--;
		if (lives == 0)
			finished = true;
	}
}

void Game::pop(Block * block)
{
	//const int sprite_num = sprite_list.size();
	for (int i = 0; i < sprite_list.size(); i++)
	{
		if (sprite_list[i] == block)
		{
			sprite_list.erase(sprite_list.begin() + i);
			break;
		}
	}

	//const int block_num = block_list.size();
	for (int i = 0; i < block_list.size(); i++)
	{
		if (block_list[i] == block)
		{
			delete block;
			block = NULL;
			block_list.erase(block_list.begin() + i);
			//std::cout << "POP BLOCK" << std::endl;
			break;
		}
	}
	if (!endless && block_list.empty())
		finished = true;
}

std::vector<Block*> Game::getBlockList()
{
	return block_list;
}

std::vector<Sprite*> Game::getSpriteList()
{
	return sprite_list;
}

sf::Vector2f Game::getWindowSize() const
{
	return sf::Vector2f(window->getSize().x, window->getSize().y);
}

sf::Vector2f Game::getMousePosition() const
{
	return sf::Vector2f(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
}

bool Game::setup()
{
	player = new Player();
	sprite_list.push_back(player);
	ball_list.push_back(new Ball());
	sprite_list.push_back(ball_list.back());
	
	if (!background_texture.loadFromFile("block-breaker\\Resources\\brick-wall.png"))
	{
		return false;
	}
	background.setTexture(background_texture);
	return true;
}

void Game::draw_sprites()
{
	window->clear();
	const int sprite_num = sprite_list.size();
	for (int i = 0; i < sprite_num; i++)
	{
		sprite_list[i]->draw(*window);
	}
	window->draw(background);
	window->display();
}

void Game::update_sprites()
{
	//const int sprite_num = sprite_list.size();
	for (int i = 0; i < sprite_list.size(); i++)
	{
		//if (sprite_list[i]->isAlive())
		 sprite_list[i]->update(*this);
	}
}

void Game::event_input()
{
	while (window->pollEvent(event))
	{
		switch(event.type)
		{
		case sf::Event::Closed:
			window->close();
		case sf::Event::MouseButtonPressed:
			ball_list[0]->launch();
			break;
		case sf::Event::KeyPressed:
			finished = true;
			break;
		}
	}
}

void Game::generateRow(int y)
{
	for (int i = 0; i < game_width / Block::block_size_x; i++)
	{
		Block* new_block;//= new Block("block2.png", left_bound + i * Block::block_size_x, upper_bound - Block::block_size_y, true);
		if (rand() % 8 == 0)
		{
			new_block = BlockGenerator::create(item, left_bound + Block::block_size_x * i, y, true);
		}
		else
		{
			new_block = BlockGenerator::create(breakable, left_bound + Block::block_size_x * i, y, true);
			new_block->setColor(BlockGenerator::getColor(BlockGenerator::ColorCode(current_color)));
			current_color = (current_color + 1) % BlockGenerator::COLOR_NUM;
		}
		block_list.push_back(new_block);
		sprite_list.push_back(new_block);
	}
	frame_passed = 0;
}

Player* Game::getPlayer()
{
	return player;
}
