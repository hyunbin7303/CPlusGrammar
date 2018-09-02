/*
You are given an array of 0s and 1s in random order.
Segregate 0s on left side and 1s on right side of the array.
Traverse array only once.

*/

#include <stdio.h>

void segregate_0and1(int arr[], int size)
{
	int left = 0, right = size - 1;
	while (left < right)
	{
		while (arr[left] == 0 && left < right)
		{
			left++;
		}
		while (arr[right] == 1 && left < right)
		{
			right--;
		}
		if (left < right)
		{
			arr[left] = 0;
			arr[right] = 1;
			left++;
			right--;
		}
	}
}



int main()
{
	int arr[] = { 0,1,0,1,1,1 };
	int i, arr_size = sizeof(arr) / sizeof(arr[0]);

	segregate_0and1(arr, arr_size);
	printf("Array after segregation ");
	for (i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}

	getchar();
	return 0;
}