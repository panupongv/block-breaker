#include "Sprite.hpp"

Sprite::Sprite(std::string texture_name, int frame_width, int frame_height, float initial_x, float initial_y)
	:
	Sprite(texture_name, frame_width, frame_height, initial_x, initial_y, 0, 0)
{
}

Sprite::Sprite(std::string texture_name, int frame_width, int frame_height, float initial_x, float initial_y, float vx, float vy)
	:
	frame_width(frame_width),
	frame_height(frame_height),
	current_frame(0),
	vx(vx),
	vy(vy)
{
	if (!texture.loadFromFile("block-breaker\\Resources\\" + texture_name))
	{
		std::cout << std::endl << texture_name << " unavailable." << std::endl;
		system("pause");
		exit(0);
	}
	sprite.setTexture(texture);
	setPosition(initial_x, initial_y);
	sprite.setTextureRect(sf::IntRect(current_frame * frame_width, 0, frame_width, frame_height));

	frame_number = static_cast<int>(texture.getSize().x / frame_width);
}

void Sprite::update()
{
	//move
	//detect collision
}

void Sprite::draw(sf::RenderWindow & window) const
{
	window.draw(sprite);
}

sf::Sprite & Sprite::getSprite()
{
	return sprite;
}

float Sprite::left() const
{
	return sprite.getPosition().x;
}

float Sprite::right() const
{
	return sprite.getPosition().x + texture.getSize().x;
}

float Sprite::top() const
{
	return sprite.getPosition().y;
}

float Sprite::bottom() const
{
	return sprite.getPosition().y + texture.getSize().y;
}

sf::Vector2f Sprite::center() const
{
	return sf::Vector2f(sprite.getPosition().x + (texture.getSize().x / 2),
						sprite.getPosition().y + (texture.getSize().y / 2));
}

void Sprite::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

void Sprite::move(float x, float y)
{
	sprite.move(x, y);
}

void Sprite::setMovement(float x, float y)
{
	vx = x;
	vy = y;
}

void Sprite::setFrame(int frame_id)
{
	if (frame_id >= 0 && frame_id < frame_number)
	{
		current_frame = frame_id;
	}
}

void Sprite::nextFrame()
{
	current_frame = (current_frame + 1) % frame_number;
}

void Sprite::resetFrame()
{
	current_frame = 0;
}
