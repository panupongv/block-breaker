#pragma once

#include "SFML/Graphics.hpp"
#include "Block.hpp"
#include "StageData.hpp"

#include <iostream>
#include <string>
#include <vector>

class Game
{
public:
	Game(sf::RenderWindow *window, std::string file_name);
	virtual ~Game();
	void run();
private:
	sf::RenderWindow *window;
	sf::Event event;
	StageData stage_data;

	vector<Sprite*> sprite_list;
	vector<Block*> block_list;

	bool finished;

	void draw_sprites();
	void update_sprites();
	void event_input();
};