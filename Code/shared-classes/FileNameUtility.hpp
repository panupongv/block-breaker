#pragma once

#include <vector>
#include <string>

class FileNameUtility
{
public :
    FileNameUtility(){};
    std::string extension_of(const std::string& file_name ) const;
    
private :
    int dot_position_of(const std::string& file_name ) const;
    bool is_dot( const char& c ) const;
};
