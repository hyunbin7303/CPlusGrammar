#include <fstream>
#include <wchar.h>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	const wchar_t* str = L"kevin";
	cout << sizeof(str) << endl;
	wchar_t checkChar;
	wifstream fileIn("kevin.txt");	//Open file
	if (fileIn)
	{
		wstring	ligne;
		while (getline(fileIn, ligne))
		{
		}
	}
	system("pause");
	return 0;
}
