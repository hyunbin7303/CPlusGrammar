
/*
#include <stdio.h>
#pragma warning(disable : 4996)
static int list[12] = { 15,20,25,35,43,44,56,69,70,72,73,80 };


int interpolationSearch(int key, int n)
{
	int mid;
	int left = 0;
	int right = n - 1;
	while (right >= left)
	{
		// mid index by interpolation
		printf("\nCalculate mid index by interpolation! \n");
		if (list[right] != list[left])
		{
			printf("Mid float = %f \n", (float)(key - list[left])*(right - left) / (list[right] - list[left]));
			mid = left + (float)(key - list[left])*(right - left) / (list[right] - list[left]);
		}
		else
		{
			mid = left;
		}
		printf("mid index = %d\n", mid);
		if (key == list[mid])
		{
			printf("Searched!! \n");
			return mid;
		}
		if (key < list[mid])
		{
			right = mid - 1;
		}
		else if (key > list[mid])
		{
			left = mid + 1;
		}
		printf("Search key is scope from low = %d to high = %d\n", left, right);
	}

	return -1;
}


void printList(int s, int e)
{
	int i;
	for (i = s; i <= e; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
}



int main(void)
{
	int i, num;
	printList(0, 11);
	scanf("%d", &num);


	printf("## interpolationSearch \n");
	i = interpolationSearch(num, 12);
	printf("\n\nResult index = %d\n", i);
	printList(0, 11);

	system("pause");
	return 0;
}
*/


#include <stdio.h>

int interpolationSearch(int arr[], int n, int x)
{
	int lo = 0, hi = (n - 1);	
	
	while (lo <= hi && x >= arr[lo] && x <= arr[hi])
	{
		// Probing the position with keeping uniform distribution in mind.
		int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo]))*(x - arr[lo]));

		// Condition of target found
		if (arr[pos] == x)
		{
			return pos;
		}
		if (arr[pos] < x)
		{
			lo = pos + 1;
		}
		else
		{
			hi = pos - 1;
		}
	}
	return -1;

}


int main()
{
	int arr[] = { 10, 12,13,14,16,20,24,25,26,27,31,32 };
	int n = sizeof(arr) / sizeof(int);
	int search = 24;
	int index = interpolationSearch(arr, n, search);
	if (index != -1)
	{
		printf("Element found at index : %d \n", index);
	}
	else
	{
		printf("Element not found. ");
	}
	return 0;
}
