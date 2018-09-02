#include <iostream>
using namespace std;

class Heap
{
private:
	int* heap;
	int capacity;
	int currentSize;

	void swap(int *a, int *b)
	{
		int t = *a;
		*a = *b;
		*b = t;
	}
public:
	Heap(int Capacity) : capacity(Capacity)
	{
		heap = new int[Capacity];
		currentSize = 0;
	}
	~Heap()
	{
		delete[] heap;
	}


	void Insert(int val)
	{
		// Heap Size Check
		if (currentSize >= capacity)
		{
			cout << "Heap is Full ! ";
			return;
		}

		// Insert in the last element
		int mPos = currentSize++;
		heap[mPos] = val;

		int parPos = (mPos - 1) / 2;

		// ChildNode > ParentNode
		while (heap[mPos] > heap[parPos])
		{
			swap(&heap[mPos], &heap[parPos]);
			mPos = parPos;
			parPos = (mPos - 1) / 2;
		}
	}

	
	int pop()
	{
		if (currentSize <= 0)
		{
			cout << "Heap is Empty !!! " << endl;
			return NULL;

		}
		int returnVal = heap[0];

		//1. Exchange with last node 
		swap(&heap[0], &heap[currentSize - 1]);

		//2. Delete last node after exchange.. 
		heap[currentSize - 1] = NULL;
		currentSize--;

		// 3. New node Find
		int root = 0;
		int leftChild;
		int rightChild;

		while (root <= currentSize - 1)
		{
			leftChild = (root + 1) * 2 - 1;
			rightChild = (root + 1) * 2;

			if (leftChild >= currentSize)
			{
				// Child node X exist
				break;
			}
			else if (rightChild >= currentSize)
			{
				// Only lefy child exist 
				if (heap[leftChild] > heap[root])
				{
					swap(&heap[leftChild] , &heap[root]);
					root = leftChild;
				}
				else
				{
					break;
				}

			}
			else
			{
				// Both child exist
				if (heap[leftChild] > heap[root] && heap[rightChild] > heap[root])
				{
					if (heap[leftChild] < heap[rightChild])
					{
						swap(&heap[rightChild], &heap[leftChild]);
						root = rightChild;
					}
					else
					{
						swap(&heap[leftChild], &heap[root]);
						root = leftChild;
					}
				}
				else if (heap[leftChild]> heap[root])
				{
					swap(&heap[leftChild] , &heap[root]);
					root = leftChild;
				}
				else if (heap[rightChild] > heap[root])
				{
					swap(&heap[rightChild], &heap[root]);
					root = rightChild;
				}
				else
				{
					break;
				}

			}
		}
		return returnVal;
	}

	
	int GetTop()
	{
		if (currentSize >= 1) return heap[0];
		else return -1;
	}






};




int main()
{
	Heap heap = Heap(100);
	for (int i = 1; i <= 8; i++) heap.Insert(i);
	for (int i = 1; i <= 8; i++) heap.Insert(8 - i + 1);
	for (int i = 1; i <= 16; i++) cout << heap.pop();
}