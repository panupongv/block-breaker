#include "Game.hpp"
#include "ResourcePath.hpp"

Game::Game(sf::RenderWindow * window, std::string character_name)
	:
	window(window),
	finished(false),
	endless(true),
	frame_passed(0),
	current_color(0),
	lives(2),
	score(0)
{
	srand(time(NULL));
	if (!setup(character_name))
	{
		std::cout << "Game setup failed" << std::endl;
	}
	
	for (int i = 8; i > -2; i--)
	{
		generateRow(upper_bound + i * Block::block_size_y);
	}	
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
		//std::cout << "Brick[" << i << "] at " << block_datas[i].getStartGrid().x << ", " << block_datas[i].getStartGrid().y << std::endl;
	}
}

Game::~Game()
{
	const int sprite_num = sprite_list.size();
	for (int i = 0; i < sprite_num; i++)
		delete sprite_list[i];
	std::cout << "Freed " << sprite_num << " sprites" << std::endl;
}

void Game::run()
{
	while (!finished && window->isOpen())
	{
		draw_sprites();
		update_sprites();
		event_input();
		if (endless)
		{
			frame_passed++;
			if (frame_passed == static_cast<int>(Block::block_size_y / Block::move_speed) * Block::frame_to_move)
			{
				generateRow(upper_bound - Block::block_size_y);
				frame_passed = 0;
			}
			if (block_list.front()->bottom() > player->getHitLine())
				finished = true;
		}
	}
	std::cout << "Game ended" << std::endl;
}

void Game::add(Ball * ball)
{
	ball_list.push_back(ball);
	sprite_list.push_back(ball);
	std::cout << ball->left() << ", " << ball->top() << std::endl;
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
		if (lives == 0)
			finished = true;
		else
			add(new Ball());
	}
}

void Game::pop(Block * block)
{
	//const int sprite_num = sprite_list.size();
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
	std::cout << breakable_block_num << std::endl;
	if (!endless && breakable_block_num == 0)
		finished = true;
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
	for (int i = 0; i < ball_list.size(); i++)
		ball_list[i]->marioBall();
}

std::vector<Block*> Game::getBlockList() const
{
	return block_list;
}

std::vector<Ball*> Game::getBallList() const
{
	return ball_list;
}

std::vector<Item*> Game::getItemList() const
{
	return item_list;
}

sf::Vector2f Game::getMousePosition() const
{
	return sf::Vector2f(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
}

bool Game::setup(std::string character_name)
{
	player = new Player(character_name);
	sprite_list.push_back(player);
	ball_list.push_back(new Ball());
	sprite_list.push_back(ball_list.back());
	
	if (!background_texture.loadFromFile(smartPath("block-breaker\\Resources\\brick-wall.png")))
	{
		return false;
	}
	background.setTexture(background_texture);

	if (!font.loadFromFile("block-breaker\\Resources\\munro.ttf"))
	{
		return false;
	}
	
	if (endless)
	{
		lives_text.setCharacterSize(30);
		score_text.setCharacterSize(30);
		lives_text.setFont(font);
		score_text.setFont(font);
		lives_text.setFillColor(sf::Color::White);
		score_text.setFillColor(sf::Color::White);
		lives_text.setPosition(left_bound + 10, lower_bound - 80);
		score_text.setPosition(left_bound + 10, lower_bound - 40);
	}
	else
	{
		lives_text.setCharacterSize(30);
		lives_text.setFont(font);
		lives_text.setFillColor(sf::Color::White);
		lives_text.setPosition(left_bound + 10, lower_bound - 40);
	}
	return true;
}

void Game::draw_sprites()
{
	window->clear();
	const int sprite_num = sprite_list.size();
	for (int i = 0; i < sprite_num; i++)
	{
		sprite_list[i]->draw(*window);
	}
	for (int i = 0; i < item_list.size(); i++)
	{
		item_list[i]->draw(*window);
	}
	window->draw(lives_text);
	if(endless)
		window->draw(score_text);
	window->draw(background);
	window->display();
}

void Game::update_sprites()
{
	//const int sprite_num = sprite_list.size();
	for (int i = 0; i < sprite_list.size(); i++)
	{
		 sprite_list[i]->update(*this);
	}
	lives_text.setString("lives: " + std::to_string(lives));
	score_text.setString("score: " + std::to_string(score));
}

void Game::event_input()
{
	while (window->pollEvent(event))
	{
		switch(event.type)
		{
		case sf::Event::Closed:
			window->close();
		case sf::Event::MouseButtonPressed:
		{
			for (int i = 0; i < ball_list.size(); i++)
			ball_list[i]->launch();
		}
			break;
		case sf::Event::KeyPressed:
			finished = true;
			break;
		}
	}
}

void Game::generateRow(int y)
{
	int column_num = game_width / Block::block_size_x;
	for (int i = 0; i < column_num; i++)
	{
		Block* new_block;//= new Block("block2.png", left_bound + i * Block::block_size_x, upper_bound - Block::block_size_y, true);
		if (rand() % 8 == 0)
		{
			new_block = BlockGenerator::create(item, left_bound + Block::block_size_x * i, y, true);
		}
		else
		{
			new_block = BlockGenerator::create(breakable, left_bound + Block::block_size_x * i, y, true);
			new_block->setColor(BlockGenerator::getColor(BlockGenerator::ColorCode(current_color)));
			current_color = (current_color + 1) % BlockGenerator::COLOR_NUM;
		}
		block_list.push_back(new_block);
		sprite_list.push_back(new_block);
	}
}

Player* Game::getPlayer()
{
	return player;
}
