#ifdef __APPLE__
#include <sys/types.h>
#include <dirent.h>
#else
#include <windows.h>
#endif

#include "DirectoryReader.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

DirectoryReader::DirectoryReader(const std::string & folder_name)
	:
	folder_name(folder_name)
{
}

std::vector<std::string> DirectoryReader::getFileNames() const
{
    vector<string> names;
#ifdef __APPLE__
    //reference
    //http://www.linuxquestions.org/questions/programming-9/c-list-files-in-directory-379323/
    
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(this->folder_name.c_str())) == NULL)
        throw invalid_argument("no such directory : " + this->folder_name);
    
    while ((dirp = readdir(dp)) != NULL)
        names.push_back(string(dirp->d_name));
    
    closedir(dp);

#else
	string search_path = folder_name + "/*.*";
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
