/*
FILE		: GreedyAlgorithm.cpp
DESCRIPTION : Find solution by always making the choice that looks optimal at the moment - 
				don't look ahead, never go back.


A greedy algorithm is an algorithmic paradigm that follows the problem solving
heuristic of making the locally optimal choice at each stage with the hope of
finding a global optimum. 
*/


#include <stdio.h>
#pragma warning(disable : 4996)
int coin[3] = { 10,5,1 };
int count[3];

int main()
{
	int m, i = 0, f = 0;
	scanf("%d", &m);
	while (i < 3)
	{
		if (coin[i] > m)
		{
			i++;
		}
		else if (coin[i] < m)
		{
			m -= coin[i];
			count[i]++;
		}
		else
		{
			f = 1;
			count[i]++;
			break;
		}
	}
	if (f)
	{
		printf("%d won coin %d, %d won coin is  %d, %d won coin is %d \n", coin[0], count[0], coin[1], count[1], coin[2], count[2]);
	}
	else
	{
		printf("Cannot find answer \n");
	}
	return 0;
}