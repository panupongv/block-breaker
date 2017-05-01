#include "Menu.hpp"

Menu::Menu(sf::RenderWindow * window)
	:
	window(window),
	width(window->getSize().x),
	height(window->getSize().y),
	finished(false)
{
	if (!title_texture.loadFromFile(smartPath("block-breaker\\Resources\\title.png")))
	{
		std::cout << "Title image not avaliable" << std::endl;
	}
	title = sf::Sprite(title_texture);
	title.setPosition(width / 2 - title_texture.getSize().x / 2, 0);
	if (!font.loadFromFile(smartPath("block-breaker\\Resources\\munro.ttf")))
	{
		std::cout << "Font not avaliable" << std::endl;
	}
	texts[0].setString("ENDLESS");
	texts[1].setString("CUSTOM");
	texts[2].setString("HIGH-SCORE");
	texts[3].setString("EXIT");
	for (int i = 0; i < TEXT_NUM; i++)
	{
		texts[i].setFont(font);
		texts[i].setCharacterSize(80);
		texts[i].setFillColor(sf::Color::White);
		//texts[i].setOutlineColor(sf::Color::White);

		sf::FloatRect text_rect = texts[i].getLocalBounds();
		texts[i].setOrigin(text_rect.left + text_rect.width / 2.0f,
			text_rect.top + text_rect.height / 2.0f);
		texts[i].setPosition(sf::Vector2f(static_cast<int>(width / 2.0f), static_cast<int>(75 * (i + 1) + 250)));
	}
	selected = -1;
}

void Menu::run()
{
	while (!finished && window->isOpen())
	{
		eventInput();
		draw();
		update();
	}
}

int Menu::getChoice() const
{
	return selected;
}

void Menu::draw()
{
	window->clear();
	window->draw(title);
	for (int i = 0; i < TEXT_NUM; i++)
		window->draw(texts[i]);
	ball.draw(*window);
	pad.draw(*window);
	window->display();
}

void Menu::update()
{
	ball.update();
	pad.update(ball);
	bool in_text = false;
	for (int i = 0; i < TEXT_NUM; i++)
	{
		if (texts[i].getGlobalBounds().intersects(sf::FloatRect(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y, 1, 1)))
		{
			in_text = true;
			selected = i;
		}
		if (selected == i)
		{
			texts[i].setFillColor(sf::Color::Red);
		}
		else
		{
			texts[i].setFillColor(sf::Color::White);
		}
	}
	if (!in_text)
		selected = -1;
}

void Menu::eventInput()
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case::sf::Event::MouseButtonPressed:
		{
			if (selected == 3)
			{
				window->close();
			}
			else if (selected != -1)
			{
				finished = true;
			}
		}
		break;
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Up)
			{
				selected = (selected + TEXT_NUM - 1) % TEXT_NUM;
				sf::Mouse::setPosition(sf::Vector2i(texts[selected].getPosition().x, texts[selected].getPosition().y), *window);
			}
			else if (event.key.code == sf::Keyboard::Down)
			{
				selected = (selected + 1) % TEXT_NUM;
				sf::Mouse::setPosition(sf::Vector2i(texts[selected].getPosition().x, texts[selected].getPosition().y), *window);
			}
			else if (event.key.code == sf::Keyboard::Return)
			{
				if (selected != -1)
					finished = true;
			}
		}
		break;
		}
	}
}

MenuBall::MenuBall()
	:
	Sprite("whiteball.png", 20, 20, 390, 210)
{
	setMovement(-2, -2.5);
}

void MenuBall::update()
{
	move();
	if (left() < 45 || right() > 755)
		setVX(-getVX());
	if (top() < 130 || bottom() > 230)
		setVY(-getVY());
}

MenuPad::MenuPad()
	:
	Sprite("whitepad.png", 200, 30, 300, 230)
{
}

void MenuPad::update(const Sprite & ball)
{
	float ball_x = ball.center().x;
	if (ball_x >= 145 && ball_x <= 655)
		setCenter(ball.center().x, center().y);
}
