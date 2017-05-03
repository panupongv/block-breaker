#include "Sprite.hpp"
#include "ResourcePath.hpp"

Sprite::Sprite(std::string texture_name, int frame_width, int frame_height)
	:
	Sprite(texture_name, frame_width, frame_height, 0, 0, 0, 0)
{
}

Sprite::Sprite(std::string texture_name, int frame_width, int frame_height, float initial_x, float initial_y)
	:
	Sprite(texture_name, frame_width, frame_height, initial_x, initial_y, 0, 0)
{
}

Sprite::Sprite(std::string texture_name, int frame_width, int frame_height, float initial_x, float initial_y, float vx, float vy)
	:
	vx(vx),
	vy(vy),
	frame_width(frame_width),
	frame_height(frame_height),
	current_frame(0)
{
	if (!texture.loadFromFile(smartPath("block-breaker\\Resources\\" + texture_name)))
	{
		std::cout << std::endl << texture_name << " unavailable." << std::endl;
		system("pause");
		exit(0);
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(current_frame * frame_width, 0, frame_width, frame_height));
	setPosition(initial_x, initial_y);

	frame_number = texture.getSize().x / frame_width;
}

void Sprite::update(Game & game)
{
	;
}

void Sprite::draw(sf::RenderWindow & window) const
{
	window.draw(sprite);
}

int Sprite::getCurrentFrame() const
{
	return current_frame;
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
	return sf::Vector2f(sprite.getPosition().x + (frame_width/ 2.0f),
						sprite.getPosition().y + (frame_height / 2.0f));
}

bool Sprite::collide(const Sprite & another_sprite) const
{
	if (this == NULL) return false;
	return left() < another_sprite.left() + another_sprite.getFrameWidth()
		 && left() + getFrameWidth() > another_sprite.left()
		&& top() < another_sprite.top() + another_sprite.getFrameHeight()
		&& top() + getFrameHeight() > another_sprite.top();
}

bool Sprite::collideHorizontally(const Sprite & another_sprite) const
{
	return collide(another_sprite) && (center().x < another_sprite.left() || center().x > another_sprite.right());
}

bool Sprite::collideVertically(const Sprite & another_sprite) const
{
	return collide(another_sprite) && (center().y < another_sprite.top() || center().y > another_sprite.bottom());
}

float Sprite::getVX() const
{
	return vx;
}

float Sprite::getVY() const
{
	return vy;
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

void Sprite::move()
{
	sprite.move(vx, vy);
}

void Sprite::move(float x, float y)
{
	sprite.move(x, y);
}

void Sprite::setVX(float x)
{
	this->vx = x;
}

void Sprite::setVY(float y)
{
	this->vy = y;
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

void Sprite::nextFrame()
{
	current_frame = (current_frame + 1) % frame_number;
	sprite.setTextureRect(sf::IntRect(current_frame * frame_width, 0, frame_width, frame_height));
}

void Sprite::setFrame(int grid_x)
{
	current_frame = grid_x % frame_number;
	sprite.setTextureRect(sf::IntRect(current_frame * frame_width, 0, frame_width, frame_height));
}

void Sprite::setMoving(bool status)
{
	moving = status;
}

