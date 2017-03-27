#pragma once

#include "SFML/Graphics.hpp"
#include "Player.hpp"
#include "Block.hpp"
#include "Ball.hpp"
#include "StageData.hpp"

#include <iostream>
#include <string>
#include <vector>

class Sprite;
class Player;
class Block;
class Ball;

class Game
{
public:
	Game(sf::RenderWindow *window, std::string file_name);
	~Game();
	void run();
	void popBlock(Sprite* block);
	Sprite* getPlayer();
	vector<Sprite*> getBlockList();
	vector<Sprite*> getSpriteList();
	sf::Vector2f getWindowSize() const;
	sf::Vector2f getMousePosition() const;
private:
	sf::RenderWindow* window;
	sf::Event event;
	StageData stage_data;

	Player* player;
	Ball* ball;

	vector<Sprite*> sprite_list;
	vector<Sprite*> block_list;

	int block_num;
	bool finished;

	void draw_sprites();
	void update_sprites();
	void event_input();
};