/*
 DirectoryReader.hpp
*/

#pragma once

#ifdef __APPLE__
#include <sys/types.h>
#include <dirent.h>
#else
#include <windows.h>
#endif

#include "FileNameUtility.hpp"
#include <iostream>
#include <iomanip>
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
    std::vector<std::string> searchFileNames( std::string search_string) const;
};
