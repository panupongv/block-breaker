#pragma once

#include "SFML/Graphics.hpp"
#include "Player.hpp"
#include "Block.hpp"
#include "Ball.hpp"
#include "Item.hpp"
#include "Explosion.hpp"
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
class Explosion;

class Game
{
public:
	Game(sf::RenderWindow *window, std::string character_name);
	Game(sf::RenderWindow *window, std::string character_name, std::string file_name);
	~Game();
	void run();

	void add(Ball* ball);
	void add(Item* item);
	void add(Explosion* explosion);
	void pop(Ball* ball);
	void pop(Block* block);
	void pop(Item* item);
	void pop(Explosion* explosion);

	void applyMarioBall();

	Player* getPlayer();
	std::vector<Block*> getBlockList() const;
	std::vector<Ball*> getBallList() const;
	std::vector<Item*> getItemList() const;

	sf::Vector2f getMousePosition() const;

public:
	static const int left_bound = 100;
	static const int right_bound = 700;
	static const int upper_bound = 10;
	static const int lower_bound = 610;
	static const int game_width = 600;
	static const int game_height = 600;
private:
	bool setup(std::string character_name);
	void draw_sprites();
	void update_sprites();
	void event_input();
	void generateRow(int y);
private:
	sf::RenderWindow* window;
	sf::Event event;
	sf::Texture background_texture;
	sf::Sprite background;
	sf::Font font;
	sf::Text lives_text;
	sf::Text score_text;

	Player* player;
	std::vector<Ball*> ball_list;
	std::vector<Block*> block_list;
	std::vector<Item*> item_list;
	std::vector<Sprite*> sprite_list;

	int lives;
	int score;
	int breakable_block_num;
	bool endless;
	bool finished;

	int current_color;
	int frame_passed;
};
