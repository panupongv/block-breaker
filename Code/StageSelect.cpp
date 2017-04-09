#include "StageSelect.hpp"

StageSelect::StageSelect(sf::RenderWindow * window, const std::vector<std::string>& file_list)
	:
	window(window),
	width(window->getSize().x),
	height(window->getSize().y),
	offset(100),
	finished(false)
{
	if (!font.loadFromFile("block-breaker\\Resources\\munro.ttf"))
	{
		std::cout << "Font not avaliable" << std::endl;
	}
	for (int i = 0; i < file_list.size(); i++)
	{
		sf::Text temp_text;
		temp_text.setString(file_list[i]);
		temp_text.setFont(font);
		temp_text.setCharacterSize(80);
		temp_text.setFillColor(sf::Color::White);
		temp_text.setOutlineColor(sf::Color::White);

		sf::FloatRect text_rect = temp_text.getLocalBounds();
		temp_text.setOrigin(text_rect.left + text_rect.width / 2.0f,
			text_rect.top + text_rect.height / 2.0f);
		temp_text.setPosition(sf::Vector2f(width / 2.0f, height / 6.0f * (i + 1) + offset));
	}

}

void StageSelect::run()
{
	while (!finished && window->isOpen())
	{
		event_input();
		draw();
		update();
	}
}

void StageSelect::event_input()
{

}

void StageSelect::draw()
{
}

void StageSelect::update()
{
}
