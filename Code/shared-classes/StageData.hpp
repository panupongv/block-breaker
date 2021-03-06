/*
 data-class/StageData.hpp
*/

#pragma once

#include "BlockData.hpp"
#include "ResourcePath.hpp"
#include <fstream>
#include <string>
#include <vector>

class StageData
{
public:
    StageData(std::string file_name);
    int getNumRow() const ;
    int getNumColumn() const ;
	std::string getPath() const ;
	std::string getFileName() const ;
    void setFileName( std::string file_name ) ;
    bool save( bool overwrite = false ) const ;
    bool load( );
	std::vector<BlockData> getBlocksData() const ;
    void addBlock( BlockData blockData );
    void addBlock( std::vector<BlockData> blockDatas );
    
private:
    const int num_row = 32;
    const int num_column = 12;
    
	std::string file_name;
	std::vector<BlockData> block_list;
};
