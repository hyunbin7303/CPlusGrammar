#include <iostream>
#include <math.h>
using namespace std;

// BinarySearch Function 
int binarySearch(int array[], int size, int searchValue)
{
	int low = 0;
	int high = size - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;

		if (searchValue == array[mid])
		{
			return mid;
		}
		else if (searchValue > array[mid])
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	return -1;
}

int DifferentForm_BinarySearch(int *mArr, int start, int end, int target)
{
	int mid = 0;
	if (start > end ){ return EOF; }
	mid = (start + end) / 2;


	if (mArr[mid] == target) { return mid; }
	else if (mArr[mid] > target) { return DifferentForm_BinarySearch(mArr, start, mid - 1, target); }
	else { return DifferentForm_BinarySearch(mArr, mid + 1, end, target); }
}

int DifferentForm_InterpolationSearch(int *mArr, int start, int end, int target)
{
	int mid = 0;
	if (mArr[start] > target || mArr[end] < target) { return EOF; }
	mid = start + ((target - mArr[start])*(end - start) / (mArr[end] - mArr[start]));

	if (mArr[mid] == target) { return mid; }
	else if (mArr[mid] > target) { return DifferentForm_InterpolationSearch(mArr, start, mid - 1, target); }
	else { return DifferentForm_InterpolationSearch(mArr, mid + 1, end, target); }
}

int formula(int *Ar, double low, double high, double key)
{
	int result=0;
	int Low = low;
	int High = high;
	
	double mid = (double)	((key - Ar[Low])*(high - low) / (Ar[High] -Ar[Low]));
	double round_up = ceilf(mid);
	result = round_up;
	return result;
}


template <typename T>
int interpolationSearch(T arr[], int size, T key)
{
	int low = 0;
	int high = size - 1;
	int mid;

	while (arr[high] != arr[low] && key >= arr[low] && key <= arr[high])
	{
		mid = low + formula(arr, low, high, key);
		if (arr[mid] < key)
		{
			low = mid;
		}
		else if (key < arr[mid])
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	if (key == arr[low])
	{
		return low;
	}
	else
	{
		return -1;
	}
}





// Main 
int main(void)
{
	int a[] = { 12,22,34,47, 55, 67,82, 98 };
	int userValue;

	cout << "enter an integer : " << endl;
	cin >> userValue;

	int result = binarySearch(a, 8, userValue);
	if (result >= 0)
	{
		cout << "The number " << a[result] << "   Was found at the element with index " << result << endl;
	}
	else
	{
		cout << "The number " << userValue << "   was not found. " << endl;
	}

	result = interpolationSearch(a, 8, userValue);
	if (result >= 0)
	{
		cout << "The number " << a[result] << " was found at the element with index " << result << endl;
	}
	else
	{
		cout << "The number " << userValue << " was not found. " << endl;
	}



	result = DifferentForm_BinarySearch(a, 0, 8, userValue);
	if (result >= 0)
	{
		cout << "DifferentForm Binary : The number " << a[result] << "was found at the element with index." << result << endl;
	}
	
	result = DifferentForm_InterpolationSearch(a, 0, 8, userValue);
	if (result >= 0)
	{
		cout << "DifferentForm Interpolation : The number " << a[result] << "was found at the element with index. " << result << endl;
	}
	else
	{
		cout << "Wrong " << endl;
	}

	return 0;
}	