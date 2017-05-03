#pragma once

#include "sfml.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

class Game;
class Block;
class Ball;

class Sprite
{
public:
	Sprite(std::string texture_name, int frame_width, int frame_height);
	Sprite(std::string texture_name, int frame_width, int frame_height, float initial_x, float initial_y);
	Sprite(std::string texture_name, int frame_width, int frame_height, float initial_x, float initial_y, float vx, float vy);

	//General
	virtual void update(Game& game); 
	void draw(sf::RenderWindow& window) const;
	
	//Get size and positions
	int getFrameWidth() const;
	int getFrameHeight() const;
	float left() const;
	float right() const;
	float top() const;
	float bottom() const;
	sf::Vector2f center() const;

	//Collisions
	bool collide(const Sprite& another_sprite) const;
	bool collideHorizontally(const Sprite& another_sprite) const;
	bool collideVertically(const Sprite& another_sprite) const;

	//Velocities
	float getVX() const;
	float getVY() const;

	//Set position
	void setPosition(float x, float y);
	void setCenter(float x, float y);

	//Move
	void move();
	void move(float x, float y);

	//Set velocities
	void setVX(float vx);
	void setVY(float vy);
	void setMovement(float x, float y);

	//Manage sprite sheet
	int getCurrentFrame() const;
	void nextFrame();
	void setFrame(int grid_x);
	void setColor(const sf::Color& color);

private:
	sf::Sprite sprite;
	sf::Texture texture;

	int frame_width;
	int frame_height;

	int frame_number;
	int current_frame;

	float vx;
	float vy;
};