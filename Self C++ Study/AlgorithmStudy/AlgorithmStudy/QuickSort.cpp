#include <stdio.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


/*
// Function : Partition function 
// Description : This function takes last element as pivot,
places the pivot element at its correct position in sorted array,
and places all smaller to left of pivot and all greater elements
to right of pivot.
*/
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		//If current element is smaller than or euqll to pivot
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}

	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		// pi is partitioning index, arr[p] is now at right place
		int pi = partition(arr, low, high);
		
		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}	



int main()
{
	int arr[] = { 1,6,7,9,10,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	printf("Sorted array : \n");
	printArray(arr, n);
	return 0;
}

/*
Quicksort is a fast sorting algorithms, which is applied in practice.
On the average, it has O(n log n) Complexity, making quicksort suitable for
sorting big data volumes.

It use the divide-and-conquer strategy is used in quicksort.
Recursion step!
1. Choose a pivot value.
- any value ( middle range of values. )
2. Partition
- Rearrange elements in such a way, that all elements which are lesster that the pivot
go to the left part of the array and all elements greater than the pivot,
go to the right part of the array.
Values equl to the pivot can stay in any part of the array.

3. Sort both parts.



On the partition step alogirthm divides the array into two parts and every
element a from the left part is less or equal than every element b from the
right parrt.
Also, a and b satisfy a<=pivot <= b inequality.


Complexity analysis



*/