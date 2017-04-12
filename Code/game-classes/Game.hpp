#pragma once

#include "SFML/Graphics.hpp"
#include "Player.hpp"
#include "Block.hpp"
#include "Ball.hpp"
#include "Item.hpp"
#include "StageData.hpp"
#include "BlockGenerator.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class Sprite;
class Player;
class Block;
class Ball;
class Item;

class Game
{
public:
	Game(sf::RenderWindow *window);
	Game(sf::RenderWindow *window, std::string file_name);
	~Game();
	void run();
	void add(Ball* ball);
	void add(Item* item);
	void popBall(Ball* ball);
	void popBlock(Block* block);
	Sprite* getPlayer();
	std::vector<Sprite*> getSpriteList();
	std::vector<Block*> getBlockList();
	sf::Vector2f getWindowSize() const;
	sf::Vector2f getMousePosition() const;
public:
	static const int left_bound = 100;
	static const int right_bound = 700;
	static const int upper_bound = 10;
	static const int lower_bound = 610;
	static const int game_width = 600;
	static const int game_height = 600;
private:
	bool setup();
	void draw_sprites();
	void update_sprites();
	void event_input();
	void generateRow(int y);
private:
	sf::RenderWindow* window;
	sf::Event event;
	sf::Texture background_texture;
	sf::Sprite background;

	Player* player;
	std::vector<Ball*> ball_list;
	std::vector<Block*> block_list;
	std::vector<Item*> item_list;
	std::vector<Sprite*> sprite_list;

	int lives;
	int block_num;
	bool endless;
	bool finished;

	int current_color;
	int frame_passed;
};
