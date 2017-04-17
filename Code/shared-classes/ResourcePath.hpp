#pragma once
#include "TemplateData.hpp"
#include <string>

std::string resourcePath();

std::string stagePath();

std::string smartPath(std::string path);

std::string texture_name_of_type( BlockType type );
