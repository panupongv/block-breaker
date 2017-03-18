#include "CSVSplitter.hpp"

CSVSplitter::CSVSplitter( string raw )
{
    setString(raw);
}

void CSVSplitter::setString( string raw )
{
    this->raw = raw;
    this->splitted = false;
}

vector<string> CSVSplitter::getResult()
{
    if( splitted )
        return result;
    
    this->splitted = true;
    
    result = vector<string>();
    string substring = "";
    int i = 0;
    while(i < raw.length())
    {
        if(raw[i] == ',')
        {
            result.push_back(substring);
            substring = "";
        }
        
        substring += raw[i];
        i++;
    }
    
    result.push_back(substring);
    
    return result;
}
