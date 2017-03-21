#pragma once

#include "Sprite.hpp"

class Ball : public Sprite
{
public:
	Ball();
	void update();
	void launch();
private:
	bool started;
};
