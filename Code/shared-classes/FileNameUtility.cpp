#include "FileNameUtility.hpp"

using namespace std;

int FileNameUtility::dot_position_of ( const string& file_name ) const
{
    int len = file_name.size();
    
    for(int pos = len-1 ; pos >= 0 ; pos--)
    {
        char character = file_name[pos];
        if(is_dot(character))
            return pos;
    }
    
    throw invalid_argument("the specify file_name -" + file_name + "- does not have any dot");
    
    return -1;
}

string FileNameUtility::extension_of(const string &file_name) const
{
    try
    {
        int dot_pos = dot_position_of(file_name);
        string extension = file_name.substr(dot_pos,file_name.size() - dot_pos);
        
        return extension;
    }
    catch( exception& e )
    {
        return "";
    }
}

bool FileNameUtility::is_dot(const char &c) const
{
    return c == '.';
}
