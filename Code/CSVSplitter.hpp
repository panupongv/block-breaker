#pragma once

#ifdef __APPLE__
#include <SFML/Graphics.hpp>
#else
#include <SFML\Graphics.hpp>
#endif

#include <vector>
#include <string>

using namespace std;

class CSVSplitter
{
public:
    CSVSplitter(string raw = "");
    void setRawString(string raw);
    vector<string> getResult();

private:
    void split();
    bool isComma(char c);
    bool isNotSplitted();
    
    string raw = "";
    bool splitted = false;
    vector<string> result;
};