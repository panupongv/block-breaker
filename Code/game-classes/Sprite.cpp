#include "Sprite.hpp"

Sprite::Sprite(std::string texture_name, int frame_width, int frame_height, float initial_x, float initial_y)
	:
	Sprite(texture_name, frame_width, frame_height, initial_x, initial_y, 0, 0)
{
}

Sprite::Sprite(std::string texture_name, int frame_width, int frame_height, float initial_x, float initial_y, float vx, float vy)
	:
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

	sprite.setScale(sf::Vector2f(static_cast<float>(frame_width) / texture.getSize().x, static_cast<float>(frame_height) / texture.getSize().y));
	setPosition(initial_x, initial_y);
	//sprite.setTextureRect(sf::IntRect(current_frame * frame_width, 0, frame_width, frame_height));
	
	this->frame_width = static_cast<int>(frame_width * sprite.getScale().x);
	this->frame_height = static_cast<int>(frame_height * sprite.getScale().y);

}

void Sprite::draw(sf::RenderWindow & window) const
{
	window.draw(sprite);
}

int Sprite::getFrameWidth() const
{
	return frame_width;
}

int Sprite::getFrameHeight() const
{
	return frame_height;
}

float Sprite::left() const
{
	return sprite.getPosition().x;
}

float Sprite::right() const
{
	return sprite.getPosition().x + frame_width;
}

float Sprite::top() const
{
	return sprite.getPosition().y;
}

float Sprite::bottom() const
{
	return sprite.getPosition().y + frame_height;
}

sf::Vector2f Sprite::center() const
{
	return sf::Vector2f(sprite.getPosition().x + (frame_width/ 2.0),
						sprite.getPosition().y + (frame_height / 2.0));
}

bool Sprite::collide(Sprite & another_sprite)
{
	return sprite.getGlobalBounds().intersects(another_sprite.sprite.getGlobalBounds());
}

bool Sprite::collideHorizontally(Sprite & another_sprite)
{
	return collide(another_sprite)
		&& (center().x < another_sprite.left() || center().x > another_sprite.right());
}

bool Sprite::collideVertically(Sprite & another_sprite)
{
	return collide(another_sprite)
		&& (center().y < another_sprite.top() || center().y > another_sprite.bottom());
}

float Sprite::getVX() const
{
	return vx;
}

float Sprite::getVY() const
{
	return vy;
}

bool Sprite::isAlive() const
{
	return alive;
}

bool Sprite::isMoving() const
{
	return moving;
}

void Sprite::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

void Sprite::setCenter(float x, float y)
{
	setPosition(x - frame_width / 2.0f, y - frame_height / 2.0f);
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

void Sprite::setColor(const sf::Color & color)
{
	sprite.setColor(color);
}

void Sprite::setMoving(bool status)
{
	moving = status;
}

void Sprite::setAlive(bool status)
{
	alive = status;
}
