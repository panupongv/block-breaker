#include "BlockBreaker.hpp"

BlockBreaker::BlockBreaker()
	:
	window(sf::VideoMode(800, 620), "Block Breaker")
{
	sf::Image icon;
	icon.loadFromFile(smartPath("block-breaker\\Resources\\iconnohelmet.png"));
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window.setFramerateLimit(60);
}

void BlockBreaker::run()
{
	while (window.isOpen())
	{
		Menu menu(&window);
		menu.run();
		CharacterSelect character_select(&window);
		switch (menu.getChoice())
		{
		case ENDLESS:
		{
			character_select.run();
			if (window.isOpen())
			{
				Game game(&window, character_select.getSelectedName());
				game.run();
				if (window.isOpen())
				{
					GameResult result(&window, game.getFinalScore());
					result.run();
				}
			}
		}
		break;
		case CUSTOM:
		{
			StageSelect stage_select(&window, smartPath("block-breaker\\Stages"));
			stage_select.run();
			if (window.isOpen() && stage_select.getSelectedName() != "")
			{
				character_select.run();
				if (window.isOpen())
				{
					Game game(&window, character_select.getSelectedName(), stage_select.getSelectedName());
					game.run();
					if (window.isOpen())
					{
						GameResult result(&window, game.getStatus());
						result.run();
					}
				}
			}
		}
		break;
		case HIGHSCORE:
			HighScore(&window).run();
			break;
		}
	}
	window.close();
}
