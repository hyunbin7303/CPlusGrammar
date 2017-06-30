#include <iostream>
#include <new>
#include <string>	
#pragma warning(disable : 4996)
using namespace std;
template<typename T>
class Kevin
{
public:
	T Addition(T Left, T Right)
	{
		return Left + Right;
	}
};


// Specialization of template class for type char*
template<> char* Kevin<char*>::Addition(char* Left, char* Right)
{
	char *str = new char[80];
	memset(str, 0, sizeof(str));
	strcat(str, Left);
	strcat(str, Right);
	return str;
}


int main()
{

	int a = 4;
	int b = 5;
	int sum;
	Kevin<int> num1;
	sum = num1.Addition(a, b);
	cout << "Sum : " << sum << endl;
	
	Kevin<double> num2;
	double sum2 = num2.Addition(5.1f, 10.3f);
	cout << "Sum Of Double numbers : " << sum2 << endl;

	/******
	// Error : C2110 Cannot add two pointers.
	Kevin<char*> TwoCharacter;
	cout << TwoCharacter.Addition("Kevin", "Park") << endl;
	******/

	Kevin<char*> str1;
	char *stringResult = str1.Addition("Kevin ", "Park");
	cout << stringResult << endl;


	return 0;
}

