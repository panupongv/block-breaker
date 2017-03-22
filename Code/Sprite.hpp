#pragma once

#ifdef __APPLE__
    #include <SFML/Graphics.hpp>
#else
    #include <SFML\Graphics.hpp>
#endif

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
	Sprite(std::string texture_name, int frame_width, int frame_height, float initial_x, float initial_y);
	Sprite(std::string texture_name, int frame_width, int frame_height, float initial_x, float initial_y, float vx, float vy);
	virtual void update(Game& game) = 0; //Game& game
	void draw(sf::RenderWindow& window) const;
	void inactivate();

	sf::Sprite& getSprite();

	float left() const;
	float right() const;
	float top() const;
	float bottom() const;
	sf::Vector2f center() const;

	float getVX() const;
	float getVY() const;

	bool isAlive() const;
	bool isMoving() const;

	void setPosition(float x, float y);
	void setCenter(float x, float y);
	void move(float x, float y);
	void setMovement(float x, float y);
	
	void setFrame(int frame_id);
	void nextFrame();
	void resetFrame();

protected:
	bool alive = true;
	bool moving;

private:
	sf::Sprite sprite;
	sf::Texture texture;

	const int frame_width;
	const int frame_height;

	int frame_number;
	int current_frame;

	float vx;
	float vy;
};