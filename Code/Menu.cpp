#include "Menu.hpp"

Menu::Menu(sf::RenderWindow * window)
	:
	window(window),
	finished(false)
{
}

void Menu::run()
{
	std::cout << "Menu started" << std::endl;
	while (!finished)
	{
		event_input();
		draw();
	}
	std::cout << "Menu ended" << std::endl;
}

void Menu::draw()
{
	window->clear();
	window->display();
}

void Menu::event_input()
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			finished = true;
			break;
		}
	}
}
