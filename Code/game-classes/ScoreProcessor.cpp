#include "ScoreProcessor.hpp"

ScoreProcessor::ScoreProcessor()
{
	std::ifstream in_file;
	in_file.open(smartPath("block-breaker\\Data\\scores.txt"));

	int temp_score; std::string temp_name;

	while (in_file >> temp_score >> temp_name)
	{
		scores.insert(make_pair(temp_score, temp_name));
	}

	in_file.close();
}

std::vector<std::pair<std::string, std::string>> ScoreProcessor::getTopScores()
{
	int count = 10;
	std::vector<std::pair<std::string, std::string>> top_scores;
	std::string temp_score; std::string temp_name;
	
	for (std::multimap<int, std::string>::reverse_iterator it = scores.rbegin(); it != scores.rend(); it++)
	{
		temp_score = std::to_string(it->first); temp_name = it->second;
		top_scores.push_back(std::make_pair(temp_score, temp_name));
		count--;
		if (count == 0)
			break;
	}
	return top_scores;
}

void ScoreProcessor::addScore(int score, std::string name)
{
	scores.insert(std::make_pair(score, name));
	std::ofstream out_file;
	out_file.open(smartPath("block-breaker\\Data\\scores.txt"));
	int count = 10;
	for (std::multimap<int, std::string>::reverse_iterator it = scores.rbegin(); it != scores.rend(); it++)
	{
		out_file << it->first << " " << it->second << std::endl;
		count--;
		if (count == 0) break;
	}
	out_file.close();
}
