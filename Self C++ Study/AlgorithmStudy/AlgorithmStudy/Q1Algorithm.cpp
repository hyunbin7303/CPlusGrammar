#include <iostream>
#include <math.h>
using namespace std;


int main(int argc, char** argv)
{
	int numbers[5] = { -5,10,8,9,20};
	int closest = numbers[0];
	bool isNegative = false;
	for (int idx = 1; idx < 5; idx++)
	{
		if (numbers[idx] < 0)
		{
			isNegative = true;
		}
		else
		{
			isNegative = false;
		}

		if (abs(numbers[idx]) < abs(closest))
		{
			closest = numbers[idx];
		}
		else if (abs(numbers[idx]) == abs(closest) && !isNegative)
		{
			closest = numbers[idx];
		}

	}


	cout << "CLOSEST : " << closest << endl;
}