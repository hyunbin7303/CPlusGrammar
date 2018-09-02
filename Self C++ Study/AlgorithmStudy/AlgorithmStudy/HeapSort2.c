


#include <stdio.h>


#define LEFT_CHILD(x)	 (2*x +1)
#define RIGHT_CHILD(x)	 (2*x + 2) 
#define PARENT(x)		 ((x-1)/2)
#define SWAP(a,b)		 {int t; t =a; a = b; b = t;} 



void HeapSort(int *base, int n);
void ViewArr(int *Arr, int n);
int main(void)
{
	int arr[10] = { 9,4,3,10,5,8,7,6,2,1 };
	ViewArr(arr, 10);
	HeapSort(arr, 10);
	ViewArr(arr, 10);
	return 0;
}

void InitHeap(int *base, int n);
void MakeHeap(int *base, int n);

void HeapSort(int * base, int n)
{
	int on = n;
	printf("Process of Heap making  \n");
	InitHeap(base, n);
	n--;
	SWAP(base[0], base[n]);
	printf("Process of Sorting \n");
	while (n > 1)
	{
		MakeHeap(base, n);
		ViewArr(base, n + 1);
		n--;
		SWAP(base[0], base[n]);
	}
	ViewArr(base, n + 1);
}

void ViewArr(int * Arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%2d ", Arr[i]);
	}
	printf("\n");
}

void InitHeap(int * base, int n)
{
	int pa = 0;
	int now;
	int i;
	for (i = 1; i < n; i++)
	{
		now = i;
		while (now > 0)
		{
			pa = PARENT(now);
			if (base[now] > base[pa])
			{
				SWAP(base[now], base[pa]);
				now = pa; // In order to go back to while loop 
			}
			else
			{
				break;
			}
		}
		ViewArr(base, i + 1);
	}
}

int FindMaxIndex(int *base, int n, int now);


void MakeHeap(int * base, int n)
{
	int now = 0;
	int mp = 0; // my position


	//if there is left child
	while (LEFT_CHILD(now) < n)
	{
		mp = FindMaxIndex(base, n, now); 
		if (mp == now)
		{
			break;
		}
		SWAP(base[mp], base[now]);
		now = mp;
	}

}

int FindMaxIndex(int * base, int n, int now)
{
	int lc = LEFT_CHILD(now);	// Left CHild
	int rc = RIGHT_CHILD(now);  // Right Child

	if (rc >= n)
	{
		if (base[now] < base[lc])
		{
			return lc;
		}
		return now;
	}

	if (base[lc] < base[rc])
	{
		return rc;
	}
	return lc;
}


