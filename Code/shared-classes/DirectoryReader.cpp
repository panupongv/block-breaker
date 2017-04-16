#include "DirectoryReader.hpp"

using namespace std;

DirectoryReader::DirectoryReader(const std::string & folder_name)
	:
	folder_name(folder_name)
{
}

std::vector<std::string> DirectoryReader::getFileNames() const
{
	std::vector<std::string> names;
#ifdef __APPLE__
    //reference
    //http://www.linuxquestions.org/questions/programming-9/c-list-files-in-directory-379323/
    
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(this->folder_name.c_str())) == NULL)
        throw invalid_argument("no such directory : " + this->folder_name);
    
    while ((dirp = readdir(dp)) != NULL)
    {
        
        names.push_back(string(dirp->d_name));
    }
    closedir(dp);

#else
	std::string search_path = folder_name + "/*.*";
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				names.push_back(fd.cFileName);
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
#endif
	return names;
}

BBStageFileFinder::BBStageFileFinder(const std::string& folder_name)
	:
	DirectoryReader(folder_name)
{}

std::vector<std::string> BBStageFileFinder::getFileNames() const
{
	std::vector<std::string> file_names = DirectoryReader::getFileNames();
    
    FileNameUtility util;
    
    for(int i = 0 ; i < file_names.size() ; ++i)
    {
        if( util.extension_of(file_names[i]) != ".bbstage")
        {
            file_names.erase(file_names.begin() + i);
            i--;
        }
    }
    
    return file_names;
}

std::vector<std::string> BBStageFileFinder::searchFileNames(std::string search_string ) const
{
    if(search_string == "")
        return getFileNames();
    
	std::vector<std::string> all = getFileNames();
	std::vector<std::string> matched;
    
    for(int i = 0 ; i < all.size() ; i++)
    {
		std::string name = all[i];
        
        if(name.find(search_string) == std::string::npos)
            continue;
        
        matched.push_back(name);
    }
    
    return matched;
}
