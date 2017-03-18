#pragma once

#include <string>
#include <vector>
#include "BlockData.hpp"

using namespace std;

class StageData
{
public:
    StageData(string file_name);
    int getNumRow() const ;
    int getNumColumn() const ;
    string getFileName() const ;
    void setFileName( string file_name ) ;
    bool save( bool overwrite = false ) const ;
    bool load( );
    vector<BlockData> getBlocksData() const ;
    void addBlock( BlockData blockData );
    
private:
    const int num_row = 20;
    const int num_column = 40;
    string file_name;
    vector<BlockData> block_list;
};