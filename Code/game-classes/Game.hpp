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
#include <algorithm>

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

	//After game informations
	bool getStatus() const;
	int getFinalScore() const;

	//Manage sprites
	void add(Ball* ball);
	void add(ShotRocket* rocket);
	void add(Item* item);
	void add(Explosion* explosion);
	void pop(Ball* ball);
	void pop(ShotRocket* rocket);
	void pop(Block* block);
	void pop(Item* item);
	void pop(Explosion* explosion);

	//Apply items
	void applyMarioBall();
	void applyFastBall();
	void applyDrunkPlayer();
	
	//Necessary sprites used outside Game class
	Player* getPlayer();
	std::vector<Block*> getBlockList() const;

	//Mouse positioning
	sf::Vector2f getMousePosition() const;
	void setMousePosition(float x, float y);
	
	//Sound player
	SoundPlayer& getSoundPlayer();

public:
	//Game boundaries
	static const int left_bound = 10;
	static const int right_bound = 610;
	static const int upper_bound = 10;
	static const int lower_bound = 610;
	static const int game_width = 600;
	static const int game_height = 600;

private:
	//Setup common factor of 2 modes
	bool setup(std::string character_name);

	void drawSprites();
	void updateSprites();
	void eventInput();
	void gameLogics();
	
	//Generate new row (endless mode)
	void generateRow(int y, bool ingame = false);
	//Decrease blocks frame to move / Increase blocks speed (endless mode)
	void accelerateBlocks();
private:
	sf::RenderWindow* window;
	sf::Event event;
	sf::Texture border_texture;
	sf::Texture life_texture;
	sf::Texture drunk_sign_texture;
	sf::Sprite border;
	sf::Sprite life;
	sf::Sprite drunk_sign;
	sf::Font font;
	sf::Text score_text;

	Player* player;
	std::vector<Ball*> ball_list;
	std::vector<Block*> block_list;
	std::vector<Item*> item_list;
	std::vector<ShotRocket*> rocket_list;
	std::vector<Sprite*> sprite_list;

	SoundPlayer sound_player;

	//Mode: endless == true/custom == false
	bool endless;

	//Game status
	int lives;
	int score;
	int breakable_block_num;
	int blocks_frame_to_move;
	bool finished;
	bool win;

	//New ball delay
	int delay;
	//End game delay
	int end_delay;

	//Block generating
	int current_color;
	int frame_passed;
	int row_generated;
};
