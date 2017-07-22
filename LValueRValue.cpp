// Understanding RValue and LValue concept
// Resource : http://www.bogotobogo.com/cplusplus/

#include <iostream>
#include <string>	
using namespace std;

class Kevin
{
private:
	int data;

public:
	Kevin() {};
	void metho(void)
	{
		cout << "METHOD" << endl;
	}

};


int Square(int& num)
{
	return num*num;
}
int SquareWithout_AND(int num)
{
	return num*num;
}
int SquareBetterOne(const int& num)
{
	return num*num;
}

int main()
{
	int i = 5;
	cout << "Value is " << Square(i) << endl; // This one is working.
	//cout << "Value is " << Square(5) << endl; // This one occurs error.
	// Reason : LValues references can only be bound to LValues but not Rvalues.
	// Below, there are solutions ..


	cout << "Value is " << SquareWithout_AND(10) << endl;
	// SquareWithoutAND(10) is an RValue.
	
	
	// LValue Example.
	i = 20; // i is LValue, 20 is RValue.
	int *pi = &i; 
	i = 10;
	Kevin kev; // k is an LValue for a user defined type.

	// RValue Example 
	i = 50; // i - LValue, 50 - RValue
	int k = i + 50; // i+50 is an RValue
	cout << "K value : " << k << endl;

	cout << SquareBetterOne(20) << endl;
	cout << SquareBetterOne(k) << endl;
	return 0;
}
