#include "GameResult.hpp"

GameResult::GameResult(sf::RenderWindow * window, int score)
	:
	window(window),
	width(window->getSize().x),
	height(window->getSize().y),
	mode(ENDLESS)
{
	if(!setup())
		std::cout << "Setup failed - GameResult" << std::endl;
	score_text.setString("score: " + std::to_string(score));
	score_text.setFont(font);
	score_text.setCharacterSize(80);
	sf::FloatRect text_rect = score_text.getLocalBounds();
	score_text.setOrigin(text_rect.left + text_rect.width / 2.0f,
		text_rect.top + text_rect.height / 2.0f);
	score_text.setPosition(sf::Vector2f(width / 2.0f, height / 2.0f));
	score_text.setFillColor(sf::Color::White);
	std::cout << score_text.getPosition().x << ", " << score_text.getPosition().y << std::endl;

}

void GameResult::run()
{
	while (!finished && window->isOpen())
	{
		eventInput();
		draw();
		update();
	}
}

void GameResult::draw()
{
	window->clear();
	if (mode == ENDLESS)
	{
		window->draw(score_text);
	}
	window->draw(done_text);
	window->display();
}

void GameResult::eventInput()
{
	while(window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (in_text)
				finished = true;
			break;
		}
	}
}

void GameResult::update()
{
	sf::FloatRect mouse(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y, 1, 1);
	in_text = mouse.intersects(done_text.getGlobalBounds());
	if(in_text)
		done_text.setFillColor(sf::Color::Red);
	else
		done_text.setFillColor(sf::Color::White);
}

bool GameResult::setup()
{
	if (!font.loadFromFile(smartPath("block-breaker\\Resources\\munro.ttf")))
		return false;
	done_text.setString("DONE");
	done_text.setFont(font);
	done_text.setCharacterSize(80);
	done_text.setPosition(600, 480);
	done_text.setFillColor(sf::Color::White);
	std::cout << done_text.getPosition().x << ", " << done_text.getPosition().y << std::endl;
	return true;
}
