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
	vector<BlockData> block_datas = stage_data.getBlocksData();
	const int block_num = block_datas.size();
	for (int i = 0; i < block_num; i++)
	{
		block_list.push_back(new Block("brick.png", block_datas[i]));
		std::cout << "Brick[" << i << "] at " << block_datas[i].getStartGrid().x << ", " << block_datas[i].getStartGrid().y << std::endl;
	}

	sprite_list.assign(block_list.begin(), block_list.end());
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

void Game::draw_sprites()
{
	window->clear();
	const int sprite_num = sprite_list.size();
	for (int i = 0; i < sprite_num; i++)
		sprite_list[i]->draw(*window);
	window->display();
}

void Game::update_sprites()
{
	const int sprite_num = sprite_list.size();
	for (int i = 0; i < sprite_num; i++)
		sprite_list[i]->update();
}

void Game::event_input()
{
	while (window->pollEvent(event))
	{
		switch(event.type)
		{
		case sf::Event::KeyPressed:
				finished = true;
				break;
		}
	}
}
