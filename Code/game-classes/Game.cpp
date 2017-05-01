#include "Game.hpp"
#include "ResourcePath.hpp"

Game::Game(sf::RenderWindow * window, std::string character_name)
	:
	window(window),
	finished(false),
	endless(true),
	frame_passed(0),

	current_color(0),
	lives(1),
	score(0),
	row_generated(0),
	breakable_block_num(0)
{
	srand(time(NULL));
	if (!setup(character_name))
	{
		std::cout << "Game setup failed" << std::endl;
	}
	
	for (int i = 8; i > -2; i--)
	{
		generateRow(i * Block::block_size_y);
	}	
	blocks_frame_to_move = block_list.front()->getFrameToMove();
}

Game::Game(sf::RenderWindow * window, std::string character_name, std::string file_name)
	:
	window(window),
	finished(false),
	endless(false),
	lives(3),
	score(0),
	breakable_block_num(0)
{
	srand(time(NULL));
	StageData stage_data(file_name);
	if (!stage_data.load())
	{
		std::cout << "No map found" << std::endl;
	}

	if (!setup(character_name))
	{
		std::cout << "Game setup failed" << std::endl;
	}

	std::vector<BlockData> block_datas = stage_data.getBlocksData();
	for (int i = 0; i <  block_datas.size(); i++)
	{
		if (block_datas[i].getType() != normal)
			breakable_block_num++;
		Block* new_block = BlockGenerator::create(block_datas[i], false);
		new_block->move(left_bound, upper_bound);
		block_list.push_back(new_block);
		sprite_list.push_back(new_block);
	}
}

Game::~Game()
{
	const int sprite_num = sprite_list.size();
	for (int i = 0; i < sprite_num; i++)
		delete sprite_list[i];
}

void Game::run()
{
	while (window->isOpen() && end_delay > 0)
	{
		drawSprites();
		updateSprites();
		eventInput();
		gameLogics();
	}
	if (win)
		sound_player.playWinSound();
	else
		sound_player.playLoseSound();
}

bool Game::getStatus() const
{
	assert(finished);
	return win;
}

int Game::getFinalScore() const
{
	assert(finished);
	return score;
}

void Game::add(Ball * ball)
{
	ball_list.push_back(ball);
	sprite_list.push_back(ball);
}

void Game::add(ShotRocket * rocket)
{
	rocket->setCenter(player->center().x, player->top() + 23);
	sprite_list.push_back(rocket);
	rocket_list.push_back(rocket);
}

void Game::add(Item * item)
{
	item_list.push_back(item);
	sprite_list.push_back(item);
}

void Game::add(Explosion * explosion)
{
	sprite_list.push_back(explosion);
}

void Game::pop(Ball * ball)
{
	for (int i = 0; i < sprite_list.size(); i++)
	{
		if (sprite_list[i] == ball)
		{
			sprite_list.erase(sprite_list.begin() + i);
			break;
		}
	}

	for (int i = 0; i < ball_list.size(); i++)
	{
		if (ball_list[i] == ball)
		{
			delete ball;
			ball = NULL;
			ball_list.erase(ball_list.begin() + i);
			break;
		}
	}
	if (ball_list.empty())
	{
		lives--;
		life_texture.loadFromFile(smartPath("block-breaker\\Resources\\life" + std::to_string(lives) + ".png"));
		life.setTexture(life_texture);
		if (lives == 0)
		{
			finished = true;
			win = false;
		}
		else
		{
			delay = 60;
		}
	}
}

void Game::pop(ShotRocket * rocket)
{
	for (int i = 0; i < sprite_list.size(); i++)
	{
		if (sprite_list[i] == rocket)
		{
			sprite_list.erase(sprite_list.begin() + i);
			break;
		}
	}

	for (int i = 0; i < rocket_list.size(); i++)
	{
		if (rocket_list[i] == rocket)
		{
			delete rocket;
			rocket = NULL;
			rocket_list.erase(rocket_list.begin() + i);
			break;
		}
	}
}

void Game::pop(Block * block)
{
	for (int i = 0; i < sprite_list.size(); i++)
	{
		if (sprite_list[i] == block)
		{
			sprite_list.erase(sprite_list.begin() + i);
			break;
		}
	}

	//const int block_num = block_list.size();
	for (int i = 0; i < block_list.size(); i++)
	{
		if (block_list[i] == block)
		{
			if (block->getBlockType() != normal)
			{
				breakable_block_num--;
				score += 10;
			}
			delete block;
			block = NULL;
			block_list.erase(block_list.begin() + i);
			break;
		}
	}
	if (!endless && breakable_block_num == 0)
	{
		finished = true;
		win = true;
	}
}

void Game::pop(Item * item)
{
	for (int i = 0; i < sprite_list.size(); i++)
	{
		if (sprite_list[i] == item)
		{
			sprite_list.erase(sprite_list.begin() + i);
			break;
		}
	}

	//const int block_num = block_list.size();
	for (int i = 0; i < item_list.size(); i++)
	{
		if (item_list[i] == item)
		{
			delete item;
			item = NULL;
			item_list.erase(item_list.begin() + i);
			break;
		}
	}
}

void Game::pop(Explosion * explosion)
{
	for (int i = 0; i < sprite_list.size(); i++)
	{
		if (sprite_list[i] == explosion)
		{
			delete explosion;
			explosion = NULL;
			sprite_list.erase(sprite_list.begin() + i);
			break;
		}
	}
}

void Game::applyMarioBall()
{
	sound_player.playMarioSound();
	for (int i = 0; i < ball_list.size(); i++)
		ball_list[i]->marioBall();
}

void Game::applyFastBall()
{
	sound_player.playSonicSound();
	for (int i = 0; i < ball_list.size(); i++)
	{
		ball_list[i]->fastBall();
	}
}

void Game::applyDrunkPlayer()
{
	sound_player.playDrunkSound();
	player->applyBeer();
	float center_line = left_bound + game_width / 2.0f;
	float current_pos = player->center().x;
	
	if (current_pos > center_line)
		sf::Mouse::setPosition(sf::Vector2i(center_line - (current_pos - center_line), player->center().y), *window);
	else
		sf::Mouse::setPosition(sf::Vector2i(center_line + (center_line - current_pos), player->center().y), *window);
}

std::vector<Block*> Game::getBlockList() const
{
	return block_list;
}

sf::Vector2f Game::getMousePosition() const
{
	return sf::Vector2f(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
}

void Game::setMousePosition(float x, float y)
{
	sf::Mouse::setPosition(sf::Vector2i(static_cast<int>(x), static_cast<int>(y)), *window);
}

SoundPlayer & Game::getSoundPlayer()
{
	return sound_player;
}

bool Game::setup(std::string character_name)
{
	player = new Player(character_name);
	sprite_list.push_back(player);
	ball_list.push_back(new Ball());
	sprite_list.push_back(ball_list.back());
	
	if (!border_texture.loadFromFile(smartPath("block-breaker\\Resources\\border.png")))
		return false;
	border.setTexture(border_texture);

	if (!life_texture.loadFromFile(smartPath("block-breaker\\Resources\\life" + std::to_string(lives) + ".png")))
		return false;
	life.setTexture(life_texture);
	if (endless)
		life.setPosition(620, window->getSize().y / 3 * 2 - life.getGlobalBounds().height / 2);
	else
		life.setPosition(620, window->getSize().y / 2 - life.getGlobalBounds().height / 2);

	if (!font.loadFromFile("block-breaker\\Resources\\munro.ttf"))
	{
		return false;
	}
	
	if (endless)
	{
		score_text.setCharacterSize(30);
		score_text.setFont(font);
		score_text.setFillColor(sf::Color::White);
		score_text.setPosition(705 - score_text.getGlobalBounds().width / 2, window->getSize().y / 3 - score_text.getGlobalBounds().height / 2);
	}

	delay = 0;
	end_delay = 60;
	
	return true;
}

void Game::drawSprites()
{
	window->clear();
	//window->draw(background);
	const int sprite_num = sprite_list.size();
	for (int i = 0; i < sprite_num; i++)
	{
		sprite_list[i]->draw(*window);
	}
	if(endless)
		window->draw(score_text);
	window->draw(life);
	window->draw(border);
	window->display();
}

void Game::updateSprites()
{
	//const int sprite_num = sprite_list.size();
	for (int i = 0; i < sprite_list.size(); i++)
	{
		if (sprite_list[i] == NULL)
			continue;
		sprite_list[i]->update(*this);
	}
	if (endless)
	{
		score_text.setString("score: " + std::to_string(score));
		score_text.setPosition(705 - score_text.getGlobalBounds().width / 2, score_text.getPosition().y);
	}
}

void Game::eventInput()
{
	while (window->pollEvent(event))
	{
		switch(event.type)
		{
		case sf::Event::Closed:
			window->close();
		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				for (int i = 0; i < ball_list.size(); i++)
				{
					ball_list[i]->launch(*this);
				}
			}
			else if(event.mouseButton.button == sf::Mouse::Right)
			{
				if (!rocket_list.empty())
				{
					rocket_list.front()->launch(*this);
					player->setHaveRocket(false);
				}
			}
		}
		break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				finished = true;
				end_delay = -1000;
			}
			break;
		}
	}
}

void Game::gameLogics()
{
	if (endless)
	{
		frame_passed++;
		if (frame_passed == static_cast<int>(Block::block_size_y / Block::move_speed) * block_list.front()->getFrameToMove())
		{
			generateRow(-Block::block_size_y, true);
			frame_passed = 0;
			row_generated++;
			if (row_generated >= 3)
			{
				accelerateBlocks();
			}
		}
		if (block_list.front()->bottom() > player->getHitLine())
			finished = true;
	}

	if (delay)
	{
		delay--;
		if (!delay && lives != 0)
			add(new Ball());
	}

	if (finished)
		end_delay--;
}

void Game::generateRow(int y, bool ingame)
{
	int column_num = game_width / Block::block_size_x;
	for (int i = 0; i < column_num; i++)
	{
		Block* new_block;//= new Block("block2.png", left_bound + i * Block::block_size_x, upper_bound - Block::block_size_y, true);
		if (rand() % 8 == 0)
		{
			new_block = BlockGenerator::create(item, left_bound + Block::block_size_x * i, upper_bound + y, endless);
		}
		else
		{
			new_block = BlockGenerator::create(breakable, left_bound + Block::block_size_x * i, upper_bound + y, endless);
			new_block->setColor(BlockGenerator::getColor(BlockGenerator::ColorCode(current_color)));
			current_color = (current_color + 1) % BlockGenerator::COLOR_NUM;
		}
		if (ingame)
			new_block->setFrameToMove(blocks_frame_to_move);
		block_list.push_back(new_block);
		sprite_list.push_back(new_block);
	}
}

void Game::accelerateBlocks()
{
	if (blocks_frame_to_move > 10)
	{
		blocks_frame_to_move--;
		for (int i = 0; i < block_list.size(); i++)
			block_list[i]->setFrameToMove(blocks_frame_to_move);
	}
}

Player* Game::getPlayer()
{
	return player;
}
