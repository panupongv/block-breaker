#pragma once

#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "ResourcePath.hpp"

class ScoreProcessor
{
public:
	ScoreProcessor();
	std::vector<std::string> getTopScores();
	void addScore(int score, std::string name);
private:
	std::multimap<int, std::string> scores;
};