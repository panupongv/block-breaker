#include "StageData.hpp"

using namespace std;

StageData::StageData(string file_name)
{
    this->file_name = file_name;
}

int StageData::getNumRow() const
{
    return this->num_row;
}

int StageData::getNumColumn() const
{
    return this->num_column;
}

string StageData::getPath() const
{
    return stagePath() + this->file_name;
}
string StageData::getFileName() const
{
    return this->file_name;
}

void StageData::setFileName(string file_name )
{
    this->file_name = file_name;
}

bool StageData::save( bool overwrite ) const
{
    string path = getPath();
    
    //check file exist
    ifstream file_in(path);
    if(file_in.good() && overwrite == false )
        return false;
    
    ofstream file(path);
    
    if(file.fail())
        return false;
    
    file << "[row]" << num_row << endl;
    file << "[column]" << num_column << endl;
    file << "[block_number]" << this->block_list.size() << endl;
    
    for(int i = 0 ; i < this->block_list.size() ; ++i)
    {
        file << "[block]" << this->block_list[i] << endl;
    }
    
    file.close();
    
    return true;
}

bool StageData::load()
{
    string path = this->getPath();
    cout << "load path : " << path << endl;
    
    ifstream file(path);
    if(file.fail())
    {
        return false;
    }
    
    this->block_list = vector<BlockData>();
    
    string line;
    while (getline(file, line))
    {
        size_t end_name_pos = line.find("]");
        string name = line.substr(1,end_name_pos-1);
        string value = line.substr(end_name_pos+1,line.size()-end_name_pos-1);
        
        if(name == "row")
        { }//nothing
        else if(name == "column")
        { }//nothing
        else if(name == "block_number")
        { }//nothing
        else
        {
            this->addBlock(BlockData(value));
        }
    }
    
    file.close();
    
    return true;
}

vector<BlockData> StageData::getBlocksData() const
{
    return this->block_list;
}

void StageData::addBlock ( BlockData blockData )
{
    block_list.push_back(blockData);
}

void StageData::addBlock ( vector<BlockData> blockDatas )
{
    this->block_list.assign(blockDatas.begin(), blockDatas.end());
}
