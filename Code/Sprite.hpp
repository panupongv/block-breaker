#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>

class Sprite
{
public:
	Sprite(std::string texture_name, int frame_width, int frame_height, float initial_x, float initial_y);
	
	virtual void update(); //Game& game
	void draw(sf::RenderWindow& window) const;

	sf::Sprite& getSprite();

	float left() const;
	float right() const;
	float top() const;
	float bottom() const;
	sf::Vector2f center() const;

	void setPosition(float x, float y);
	void move(float x, float y);
	
	void setFrame(int frame_id);
	void nextFrame();
	void resetFrame();
private:
	sf::Sprite sprite;
	sf::Texture texture;

	const int frame_width;
	const int frame_height;

	int frame_number;
	int current_frame;
};