
#include <iostream>
#include <string>
using namespace std;





void merge(int a[], int left_low, int left_high, int right_low, int right_high)
{
	int length = right_high - left_low + 1;
	int *temp = new int[length];
	int left = left_low;
	int right = right_low;
	for (int i = 0; i < length; ++i) {
		if (left > left_high)
			temp[i] = a[right++];
		else if (right > right_high)
			temp[i] = a[left++];
		else if (a[left] <= a[right])
			temp[i] = a[left++];
		else
			temp[i] = a[right++];
	}

	for (int i = 0; i< length; ++i)
		a[left_low++] = temp[i];
}

void merge_sort1(int a[], int low, int high) {
	if (low >= high)                  //Base case: 1 value to sort->sorted
		return;                         //(0 possible only on initial call)
	else {
		int mid = (low + high) / 2;       //Approximate midpoint*
		merge_sort1(a, low, mid);        //Sort low to mid part of array
		merge_sort1(a, mid + 1, high);     //Sort mid+1 to high part of array
		merge(a, low, mid, mid + 1, high); //Merge sorted subparts of array
	}
}
void merge_sort(int a[], int length) {
	merge_sort1(a, 0, length - 1);
}



int main()
{
	int arr[10] = { 10,5,4,20,25,1,2,3,15,12 };
	merge_sort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";

	}
	cout << endl;
	return 0; 
}