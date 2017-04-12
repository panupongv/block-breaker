#pragma once

#include <string>
#include <vector>

class DirectoryReader
{
public:
	DirectoryReader(const std::string& folder_name);
	std::vector<std::string> getFileNames() const;
private:
	std::string folder_name;
};

class BBStageFileFinder : public DirectoryReader
{
public:
    BBStageFileFinder(const std::string& folder_name);
    std::vector<std::string> getFileNames() const;
};
