
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <wchar.h>
using namespace std;
int main()
{
	char c1 = 'A';
	wchar_t w1 = L'A'; 
	// L is the prefix for wide character literals and wide -character string 
	// literals which tells the compiler that the character or str is of type wide-char.
	wchar_t w2 = 'B';
	cout << "Character size : " << sizeof(c1) << endl;
	cout << "Wide character size : " << sizeof(w1) << endl;
	wchar_t warr[] = L"Hello. My name is kevin.";
	wchar_t warr2[] = L"A";

	cout << "wide character array size : " << sizeof(warr) << endl;
	cout << "wide character array size : " << sizeof(warr2) << endl;

	wchar_t warr3[30];
	cout << "wide3 character array size : " << sizeof(warr3) << endl;
	wscanf(L"%s", warr3);
	wprintf(L"%s\n", warr3);

	wchar_t warr4[30];
	wcscpy(warr4, warr3);
	wprintf(L"%s\n", warr4);
	cout << "Warr 4 info : " << warr4 << endl;


	system("pause");
	return 0;
}