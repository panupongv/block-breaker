#pragma once

#ifdef __APPLE__
    #include <SFML/Graphics.hpp>
#else
    #include <SFML\Graphics.hpp>
#endif

#include "Menu.hpp"
#include "Game.hpp"
#include "DirectoryReader.hpp"
#include <iostream>

int main()
{
	vector<string> names = DirectoryReader("block-breaker\\stages").getFileNames();
	for (int i = 0; i < names.size(); i++)
		cout << names[i] << endl;
	cout << "*******\n";

	sf::RenderWindow window(sf::VideoMode(800, 620), "SFML works!");//, sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		Menu menu(&window);
		menu.run();
		switch (menu.getChoice())
		{
		case 0:
			Game(&window).run();
			break;
		case 1:
			Game(&window, "stage1.csv").run();
			break;
		}
	}
	window.close();

	system("pause"); 
	return 0;
}