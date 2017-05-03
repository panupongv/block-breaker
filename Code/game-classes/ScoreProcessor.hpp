#pragma once

#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ResourcePath.hpp"

class ScoreProcessor
{
public:
	ScoreProcessor();
	
	//Vector of pair of score and player name in string
	std::vector<std::pair<std::string, std::string>> getTopScores();

	//Add score and player's name to map, sorted and rewrite
	void addScore(int score, std::string name);
private:
	std::multimap<int, std::string> scores;
};