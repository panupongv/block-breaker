#include "ScoreProcessor.hpp"

ScoreProcessor::ScoreProcessor()
{
	std::ifstream in_file;
	in_file.open(smartPath("block-breaker\\Data\\scores.txt"));

	int temp_score; std::string temp_name;

	while (in_file >> temp_score >> temp_name)
	{
		//std::cout << temp_score << " " << temp_name << std::endl;
		scores.insert(make_pair(temp_score, temp_name));
		//std::cout << scores.rbegin()->first << ", " << scores.rbegin()->second << std::endl;
	}

	in_file.close();
}

std::vector<std::string> ScoreProcessor::getTopScores()
{
	int count = 10;
	
	std::vector<std::string> top_scores;
	
	std::string temp_score; std::string temp_name;
	std::string line;
	std::ostringstream line_strm(line);
	line_strm.fill('-');
	
	for (std::multimap<int, std::string>::reverse_iterator it = scores.rbegin(); it != scores.rend(); it++)
	{
		temp_score = std::to_string(it->first); temp_name = it->second;
		line_strm << std::left << std::setw(10) << temp_score << std::right << std::setw(10) << temp_name;
		top_scores.push_back(line_strm.str());
		line_strm.str("");
		line_strm.clear();
		count--;
		if (count == 0)
			break;
	}

	return top_scores;
}

void ScoreProcessor::addScore(int score, std::string name)
{
	std::ofstream out_file;
	out_file.open(smartPath("block-breaker\\Data\\scores.txt"));
	for (std::multimap<int, std::string>::iterator it = scores.begin(); it != scores.end(); it++)
	{
		out_file << it->first << " " << it->second << std::endl;
	}
	out_file << score << " " << name << std::endl;
	out_file.close();
}
