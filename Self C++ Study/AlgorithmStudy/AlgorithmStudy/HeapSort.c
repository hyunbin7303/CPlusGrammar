#include <stdio.h>
#pragma warning(disable : 4996)
void main()
{
	int heap[10], no, i, j, c, root, temp;
	/*printf("\n Enter no of elements : ");
	scanf("%d", &no);
	printf("\n Enter the nos ");
	for (i = 0; i < no; i++)
	{
		scanf("%d", &heap[i]);

	}*/
	heap[0] = 15;
	heap[1] = 7;
	heap[2] = 9;
	heap[3] = 2;
	heap[4] = 3;
	heap[5] = 1;
	heap[6] = 10;

	for (i = 1; i < 7; i++)
	{
		c = i;
		do
		{
			root = (c - 1) / 2;
			if (heap[root] < heap[c])
			{
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}

	printf("Heap array : ");
	for (i = 0; i < 7; i++)
	{
		printf("%d\t", heap[i]);
	}
	for (j = 7 - 1; j >= 0; j--)
	{
		temp = heap[0];
		heap[0] = heap[j];
		heap[j] = temp;
		root = 0;

		do
		{
			c = 2 * root + 1;
			if ((heap[c] < heap[c + 1]) && c < j - 1)
			{
				c++;
			}
			if (heap[root] < heap[c] && c < j)
			{
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < j);
		
	}
	printf("\n The sorted array is : ");
	for (i = 0; i < 7; i++)
	{
		printf("\t %d ", heap[i]);
	}
	printf("\n Complexity : \n Best case = Average case = Worst case = O(n logn) \n");


}