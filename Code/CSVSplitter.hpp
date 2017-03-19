#pragma once

#ifdef __APPLE__
#include <SFML/Graphics.hpp>
#else
#include <SFML\Graphics.hpp>
#endif

//this comment added from test-1-branch

#include <vector>
#include <string>

using namespace std;

class CSVSplitter
{
public:
    CSVSplitter(string raw = "");
    void setString(string raw);
    vector<string> getResult();

private:
    string raw = "";
    bool splitted = false;
    vector<string> result;
};