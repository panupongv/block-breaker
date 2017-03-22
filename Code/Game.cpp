#include "Game.hpp"

Game::Game(sf::RenderWindow * window, std::string file_name)
	:
	window(window),
	stage_data(file_name),
	finished(false)
{
	if (!stage_data.load())
	{
		std::cout << "No map found" << std::endl;
	}

	vector< vector<Sprite*> > lists;
	lists.push_back(sprite_list);
	lists.push_back(block_list);

	ball = new Ball();

	vector<BlockData> block_datas = stage_data.getBlocksData();
	block_num = block_datas.size();
	for (int i = 0; i < block_num; i++)
	{
		Block * temp_block = new Block(block_datas[i]);
		block_list.push_back(new Block("brick.png", block_datas[i]));
		std::cout << "Brick[" << i << "] at " << block_datas[i].getStartGrid().x << ", " << block_datas[i].getStartGrid().y << std::endl;
	}
	sprite_list.assign(block_list.begin(), block_list.end());
	sprite_list.push_back(ball);
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
	while (!finished)
	{
		draw_sprites();
		update_sprites();
		event_input();
	}
	std::cout << "Game ended" << std::endl;
}

vector<Sprite*>& Game::getBlockList()
{
	return block_list;
}

sf::Vector2f Game::getWindowSize() const
{
	return sf::Vector2f(window->getSize().x, window->getSize().y);
}

sf::Vector2f Game::getMousePosition() const
{
	return sf::Vector2f(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
}

void Game::draw_sprites()
{
	window->clear();
	const int sprite_num = sprite_list.size();
	for (int i = 0; i < sprite_num; i++)
	{
		if(sprite_list[i]->isAlive())
			sprite_list[i]->draw(*window);
	}
	window->display();
}

void Game::update_sprites()
{
	const int sprite_num = sprite_list.size();
	for (int i = 0; i < sprite_num; i++)
	{
		if (sprite_list[i]->isAlive())
			sprite_list[i]->update(*this);
	}
}

void Game::event_input()
{
	while (window->pollEvent(event))
	{
		switch(event.type)
		{
		case sf::Event::MouseButtonPressed:
			ball->launch();
			break;
		case sf::Event::KeyPressed:
			finished = true;
			break;
		}
	}
}

void Game::removeBlock()
{
	block_num--;
	if (block_num == 0)
		finished = true;
}
