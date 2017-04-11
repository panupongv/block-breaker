#include "DirectoryReader.hpp"

using namespace std;

DirectoryReader::DirectoryReader(const std::string & folder_name)
	:
	folder_name(folder_name)
{
}

std::vector<std::string> DirectoryReader::getFileNames() const
{
	vector<string> names;
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
	return names;
}
