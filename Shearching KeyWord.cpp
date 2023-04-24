#include "Shearching KeyWord.h"
using namespace std;
namespace fs = filesystem;
#pragma comment(lib, "Winmm.lib")


int main(int argc, char* argv[])
{
	string targetPath, keyWord, name, text;
	cout << "Enter Target Path : ";
	getline(cin, targetPath);
	cout << "Enter Keyword : ";
	getline(cin, keyWord);
	bool open;
	for (const auto& target : fs::directory_iterator(targetPath))
	{
		if (ext(target.path().generic_string()) == ".txt")
		{
			name = getName(target.path().generic_string());
			ifstream file(target.path());
			open = file.is_open();
			if (!open)
			{
				cout << "One File Couldn't Be Opened";
			}
			else
			{
				getline(file, text);
				const char* found = strstr(lower(text).c_str(), lower(keyWord).c_str());
				const char* found2 = strstr(lower(name).c_str(), lower(keyWord).c_str());
				if (found or found2)
				{
					cout << "\n\n\n" << name << "\n\n" << text;
				}
			}
		}
	}
	return 0;
}