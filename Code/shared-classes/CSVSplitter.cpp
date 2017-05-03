/*
 util/CSVSplitter.cpp
*/

#include "CSVSplitter.hpp"

CSVSplitter::CSVSplitter( string raw )
{
    setRawString(raw);
}

void CSVSplitter::setRawString( string raw )
{
    this->raw = raw;
    this->splitted = false;
}

vector<string> CSVSplitter::getResult()
{
    if( this->isNotSplitted() )
    {
        this->split();
    }
    
    return result;
}

void CSVSplitter::split()
{
    this->result.clear();
    string value;
    
    for(int i = 0 ; i < raw.length();i++)
    {
        char character = raw[i];
        
        if(isComma(character))
        {
            this->result.push_back(value);
            value = "";
        }
        else
        {
            value += character;
        }
    }
	this->result.push_back(value);
    this->splitted = true;
}

bool CSVSplitter::isComma(char c)
{
    return c == ',';
}

bool CSVSplitter::isNotSplitted()
{
    return this->splitted == false;
}
