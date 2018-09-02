#include <stdio.h>


void quickSort(int numbers[], int array_size);
void q_sort(int numbers[], int left, int right);

void quickSortAlgorithm(int arr[], int left, int right);


int main(int argc, char **argv)
{
	int itemSize = 0;
	int array[] = { 3,8,0,2,1,4,20,10 };

	itemSize = sizeof(array) / sizeof(array[0]);
	quickSort(array, itemSize);
	for (int i = 0; i < itemSize; i++)
	{
		printf("%d \t", array[i]);
	}
	printf("\n");
	int array2[] = { 3,6,2,1,3,40,2,1,20 };

	printf("Implementation : ");
	//quickSortAlgorithm(array2, 0, 9);
	/*
	for (int i = 0; i < 8; i++)
	{
		printf("%d \t", array2[i]);
	}*/

	return 0;
}


void quickSort(int numbers[], int array_size)
{
	q_sort(numbers, 0, array_size - 1);
}


void q_sort(int numbers[], int left, int right)
{
	
	int pivot, l_hold, r_hold;
	l_hold = left;
	r_hold = right;
	pivot = numbers[left];
	while (left < right)
	{
		while ((numbers[right] >= pivot) && (left < right))
		{
			right--;
		}
		if (left != right)
		{
			numbers[left] = numbers[right];
		}
		while ((numbers[left] <= pivot) && (left < right))
		{
			left++;
		}

		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}

	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;

	if (left < pivot)
	{
		q_sort(numbers, left, pivot - 1);

	}
	if(right>pivot)
	{
		q_sort(numbers, pivot + 1, right);
	}
}

void quickSortAlgorithm(int arr[], int left, int right)
{
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];
	int temp;
	do
	{
		while (arr[i] < pivot)
		{
			i++;
		}
		while (arr[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
	{
		quickSortAlgorithm(arr, left, j);
	}
	if (i < right)
	{
		quickSortAlgorithm(arr, i, right);
	}
}
