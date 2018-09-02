#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//bool isPrime(int num)
//{
//	if (!(num % 2))
//	{
//		return false;
//	}
//	for (int i = 3; i <= sqrt((double)num); i += 2)
//	{
//		if (!(num%i))
//		{
//			return false;
//		}
//	}
//	return true;
//}

//
//int main()
//{
//	int arr[100];
//	for (int i = 0; i < 100; i++)
//	{
//		arr[i] = i;
//	}
//	for (int i = 0; i < 100; i++)
//	{
//		if (!(arr[i] % 2 == 0 || arr[i] %3== 0))
//		{
//			cout << arr[i] << " ";
//		}
//	}
//	cout << endl;
//	return 0;
//}



int main()
{
	for (int i = 2; i<100; i++)
	{
		bool prime = true;
		for (int j = 2; j*j <= i; j++)
		{
			if (i % j == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime) cout << i << " ";
	}
	return 0;
}


/*
int main()
{
	std::vector<int> primes;
	primes.push_back(2);
	for (int i = 3; i < 100; i++)
	{
		bool prime = true;
		for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++)
		{
			if (i % primes[j] == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime)
		{
			primes.push_back(i);
			cout << i << " ";
		}
	}

	return 0;
}*/