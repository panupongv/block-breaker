#pragma once

#include <stirng>
#include "BlockData.hpp"

using namespace std;

class StageData
{
public:
    StageData(string file_name);
    int getNumRow() const ;
    int getNumColumn() const ;
    string getFileName() const ;
    void setFileName() ;
    void save() const ;
    void load();
    const Vector<BlockData> getBlocks() const ;
    void addBlock( BlockData blockData );
    
private:
    const int num_row = 20;
    const int num_column = 40;
    string file_name;
    int num_block;
    vector<BlockData> block_list;
};