#include <stdio.h>


//Normal recursion
int FactorialRec(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n*FactorialRec(n - 1);
	}
}

int FactorialTailRec(int n, int res)
{
	if (n == 1)
	{
		return res;
	}
	return FactorialTailRec(n - 1, res*n);
}
int FactorialTail(int n)
{
	return FactorialTailRec(n, 1);
}
int FactorialTailRecLoop(int n)
{
	int res = 1;
	for (; n > 0; n--)
	{
		res = res * n;
	}
	return res;
}

int main(int arc, char** argv)
{
	printf("%d\n", FactorialRec(5));
	printf("%d\n", FactorialTail(5));
	printf("%d\n", FactorialTailRecLoop(5));
}