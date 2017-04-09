#include "Game.hpp"

Game::Game(sf::RenderWindow * window)
	:
	window(window),
	finished(false),
	endless(true),
	frame_past(0)
{
	if (!initializeAttributes())
	{
		std::cout << "Game setup failed" << std::endl;
	}
	for (int i = 0; i < game_width / Block::block_size_x; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Block* new_block = new Block("block3.png", left_bound + Block::block_size_x * i, upper_bound + Block::block_size_y * j, true);
			block_list.push_back(new_block);
			sprite_list.push_back(new_block);
		}
	}
}

Game::Game(sf::RenderWindow * window, std::string file_name)
	:
	window(window),
	finished(false),
	endless(false)
{
	StageData stage_data(file_name);
	if (!stage_data.load())
	{
		std::cout << "No map found" << std::endl;
	}

	if (!initializeAttributes())
	{
		std::cout << "Game setup failed" << std::endl;
	}

	vector<BlockData> block_datas = stage_data.getBlocksData();
	block_num = block_datas.size();
	for (int i = 0; i < block_num; i++)
	{
		//Block * temp_block = new Block(block_datas[i]);
		Block* new_block = new Block("block5.png", block_datas[i]);
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
	std::cout << "Freed sprites" << std::endl;
}

void Game::run()
{
	while (!finished && window->isOpen())
	{
		draw_sprites();
		update_sprites();
		event_input();
		frame_past++;
		if (frame_past == static_cast<int>(Block::block_size_y / Block::move_speed))
			generateBlock();
	}
	std::cout << "Game ended" << std::endl;
}

void Game::popBlock(Sprite * block)
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

vector<Sprite*> Game::getBlockList()
{
	return block_list;
}

vector<Sprite*> Game::getSpriteList()
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

bool Game::initializeAttributes()
{
	player = new Player();
	ball = new Ball();

	sprite_list.push_back(player);
	sprite_list.push_back(ball);

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
			ball->launch();
			break;
		case sf::Event::KeyPressed:
			finished = true;
			break;
		}
	}
}

void Game::generateBlock()
{
	for (int i = 0; i < game_width / Block::block_size_x; i++)
	{
		Block* new_block = new Block("block2.png", left_bound + i * Block::block_size_x, upper_bound - Block::block_size_y, true);
		block_list.push_back(new_block);
		sprite_list.push_back(new_block);
	}
	frame_past = 0;
}

Sprite* Game::getPlayer()
{
	return player;
}
