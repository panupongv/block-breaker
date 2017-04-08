#include "Menu.hpp"

Menu::Menu(sf::RenderWindow * window)
	:
	window(window),
	width(window->getSize().x),
	height(window->getSize().y),
	finished(false)
{
	if (!title_texture.loadFromFile("block-breaker\\Resources\\title.png"))
	{
		std::cout << "Title image not avaliable" << std::endl;
	}
	title = sf::Sprite(title_texture);
	title.setPosition(width / 2 - title_texture.getSize().x / 2, 50);
	if (!font.loadFromFile("block-breaker\\Resources\\munro.ttf"))
	{
		std::cout << "Font not avaliable" << std::endl;
	}
	texts[0].setString("ENDLESS");
	texts[1].setString("CUSTOM");
	texts[2].setString("EXIT");
	for (int i = 0; i < TEXT_NUM; i++)
	{
		texts[i].setFont(font);
		texts[i].setCharacterSize(80);
		texts[i].setFillColor(sf::Color::White);
		texts[i].setOutlineColor(sf::Color::White);

		sf::FloatRect text_rect = texts[i].getLocalBounds();
		texts[i].setOrigin(text_rect.left + text_rect.width / 2.0f,
			text_rect.top + text_rect.height / 2.0f);
		texts[i].setPosition(sf::Vector2f(width / 2.0f, height / 6.0f * (i + 1) + 200));

		std::cout << (texts[i].getCharacterSize() * texts[i].getString().getSize()) << ", " << texts[i].getPosition().x << " " << texts[i].getPosition().y << std::endl;
		/*texts[i].setPosition(sf::Vector2f((width / 2) - (texts[i].getCharacterSize() * texts[i].getString().getSize() / 2.0),
			height / (3 + 1) * (i + 1)));
		std::cout << (texts[i].getCharacterSize() * texts[i].getString().getSize()) << ", *///" << texts[i].getPosition().x << " " << texts[i].getPosition().y << std::endl;
	}
	texts[0].setFillColor(sf::Color::Red); 

	selected = 0;
}

void Menu::run()
{
	std::cout << "Menu started" << std::endl;
	while (!finished && window->isOpen())
	{
		event_input();
		draw();
		update();
	}
	std::cout << "Menu ended" << std::endl;
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
	window->display();
}

void Menu::update()
{
	bool in_text = false;
	for (int i = 0; i < TEXT_NUM; i++)
	{
		if (texts[i].getGlobalBounds().intersects(sf::FloatRect(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y, 1, 1)))
		{
			in_text = true;
			selected = i;
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

void Menu::event_input()
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
			if (selected == 2)
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
			finished = true;
			break;
		}
	}
}
