//#pragma once

#include "sfml.hpp"

#include "Menu.hpp"
#include "CharaterSelect.hpp"
#include "StageSelect.hpp"
#include "Game.hpp"
#include "ResourcePath.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 620), "Block Breaker");//, sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	/*sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("block-breaker\\resources\\mariosong.wav"))
		std::cout << "not loaded" << std::endl;
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();*/
	/*sf::Music music;
	music.openFromFile("block-breaker\\Resources\\mariosong.wav");
	music.play();
	sf::Music a;
	a.openFromFile("block-breaker\\Resources\\bounce.wav");
	a.play();*/

	while (window.isOpen())
	{

		Menu menu(&window);
		menu.run();
		CharacterSelect character_select(&window);
		switch (menu.getChoice())
		{
		case 0:
			character_select.run();
			if(window.isOpen())
				Game(&window, character_select.getSelectedName()).run();
			break;
           case 1:
            StageSelect stage_select(&window, smartPath("block-breaker\\Stages"));
			stage_select.run();
			if(window.isOpen())
				Game(&window, character_select.getSelectedName(), stage_select.getSelectedName()).run();
			break;
		}
	}
	window.close();

	system("pause"); 
	return 0;
}
