#pragma once

#include "SFML/Graphics.hpp"
#include "Player.hpp"
#include "Block.hpp"
#include "Ball.hpp"
#include "Item.hpp"
#include "Explosion.hpp"
#include "StageData.hpp"
#include "BlockGenerator.hpp"
#include "SoundPlayer.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>

class Sprite;
class Player;
class Block;
class Ball;
class ShotRocket;
class Item;
class Explosion;

class Game
{
public:
	Game(sf::RenderWindow *window, std::string character_name);
	Game(sf::RenderWindow *window, std::string character_name, std::string file_name);
	~Game();
	void run();
	bool getStatus() const;
	int getFinalScore() const;

	void add(Ball* ball);
	void add(ShotRocket* rocket);
	void add(Item* item);
	void add(Explosion* explosion);
	void pop(Ball* ball);
	void pop(ShotRocket* rocket);
	void pop(Block* block);
	void pop(Item* item);
	void pop(Explosion* explosion);

	void applyMarioBall();
	void applyFastBall();
	void applyDrunkPlayer();

	Player* getPlayer();
	std::vector<Block*> getBlockList() const;

	sf::Vector2f getMousePosition() const;
	void setMousePosition(float x, float y);
	SoundPlayer& getSoundPlayer();

public:
	static const int left_bound = 10;
	static const int right_bound = 610;
	static const int upper_bound = 10;
	static const int lower_bound = 610;
	static const int game_width = 600;
	static const int game_height = 600;
private:
	bool setup(std::string character_name);
	void drawSprites();
	void updateSprites();
	void eventInput();
	void gameLogics();
	void generateRow(int y, bool ingame = false);
	void accelerateBlocks();
private:
	sf::RenderWindow* window;
	sf::Event event;
	sf::Texture border_texture;
	sf::Texture life_texture;
	sf::Sprite border;
	sf::Sprite life;
	sf::Font font;
	sf::Text score_text;

	Player* player;
	std::vector<Ball*> ball_list;
	std::vector<Block*> block_list;
	std::vector<Item*> item_list;
	std::vector<ShotRocket*> rocket_list;
	std::vector<Sprite*> sprite_list;

	SoundPlayer sound_player;

	int lives;
	int score;
	int breakable_block_num;
	int blocks_frame_to_move;
	int delay;
	int end_delay;
	bool finished;
	bool endless;
	bool win;

	int current_color;
	int frame_passed;
	int row_generated;
};
