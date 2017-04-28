#include "HighScore.hpp"

HighScore::HighScore(sf::RenderWindow * window)
	:
	window(window),
	width(window->getSize().x),
	height(window->getSize().y),
	finished(false)
{
	if (!font.loadFromFile(smartPath("block-breaker\\Resources\\munro.ttf")))
	{
		std::cout << "Font not avaliable" << std::endl;
	}
	ScoreProcessor pcs;
	std::vector<std::string> strings = pcs.getTopScores();
	for (int i = 0; i < strings.size(); i++)
	{
		sf::Text temp_text;
		temp_text.setString(strings[i]);
		temp_text.setFont(font);
		temp_text.setCharacterSize(40);
		temp_text.setFillColor(sf::Color::White);
		temp_text.setOutlineColor(sf::Color::White);

		sf::FloatRect text_rect = temp_text.getLocalBounds();
		temp_text.setOrigin(text_rect.left + text_rect.width / 2.0f,
			text_rect.top + text_rect.height / 2.0f);
		temp_text.setPosition(sf::Vector2f(width / 2.0f, 100 + (45 * (i + 1))));
		score_list.push_back(temp_text);
	}
	head.setString("Top scorers");
	head.setFont(font);
	head.setCharacterSize(60);
	head.setFillColor(sf::Color::White);
	head.setOutlineColor(sf::Color::White);
	sf::FloatRect text_rect = head.getLocalBounds();
	head.setOrigin(text_rect.left + text_rect.width / 2.0f,
		text_rect.top + text_rect.height / 2.0f);
	head.setPosition(sf::Vector2f(width / 2.0f, 75));
}

void HighScore::run()
{
	while (!finished && window->isOpen())
	{
		draw();
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			else if (event.type == sf::Event::MouseButtonPressed)
				finished = true;
		}
	}
}

void HighScore::draw()
{
	window->clear();
	for (int i = 0; i < score_list.size(); i++)
		window->draw(score_list[i]);
	window->draw(head);
	window->display();
}
