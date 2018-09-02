

#include <stdio.h>

int LSearch(int arr[], int len, int target)
{
	int i = 0;
	int opCnt = 0;
	for (; i < len; i++)
	{
		opCnt++;
		if (arr[i] == target)
		{
			printf("How many times : %d\n", opCnt);
			return i;
		}
	}
	printf("How many times : %d\n", opCnt);
	return -1;
}
int BSearch(int arr[], int len, int target)
{
	int start = 0;
	int last = len - 1;
	int mid = 0;
	int opCnt = 0;
	while (start <= last)
	{
		mid = (start + last) / 2;
		opCnt++;
		if (arr[mid] == target)
		{
			printf("How many Compare : %d\n", opCnt);
			return mid;
		}
		else
		{
			if (arr[mid] > target)
			{
				last = mid - 1;

			}
			else
			{
				start = mid + 1;
			}
		}
	}
	printf("How many compare : %d \n", opCnt);
	return -1;
}



int main(int argc, char** argv)
{
	int arr1[500] = { 0, 20}; // declare arr1 array and initialize to 0.
	int arr2[5000] = { 0, }; // Declare arr2 array and initialize to 0.
	int arr3[50000] = { 0, };
	int idx = 0;

	idx = LSearch(arr1, sizeof(arr1) / sizeof(int), 20);
	if (idx == -1)
	{
		printf("L(500) Search Fail \n");
	}
	else
	{
		printf("Target Index %d \n", idx);
	}


	idx = LSearch(arr2, sizeof(arr2) / sizeof(int), 1);
	if (idx == -1)
	{
		printf("L(5000) Search Fail \n");
	}
	else
	{
		printf("Target Index %d \n", idx);
	}


	idx = LSearch(arr3, sizeof(arr3) / sizeof(int), 1);
	if (idx == -1)
	{
		printf("L(50000) Search Fail \n");
	}
	else
	{
		printf("Target Index %d\n", idx);
	}

	idx = BSearch(arr1, sizeof(arr1) / sizeof(int), 1);
	if (idx == -1)
	{
		printf("Target Index %d\n", idx);
	}
	else
	{
		printf("Target Index %d\n", idx);
	}
	idx = BSearch(arr2, sizeof(arr2) / sizeof(int), 1);
	if (idx == -1)
	{
		printf("Target Index %d\n", idx);
	}
	else
	{
		printf("Target Index %d\n", idx);
	}
	idx = BSearch(arr3, sizeof(arr3) / sizeof(int), 1);
	if (idx == -1)
	{
		printf("Target Index %d\n", idx);
	}
	else
	{
		printf("Target Index %d\n", idx);
	}




}