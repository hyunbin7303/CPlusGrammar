// Heap data structure using STL container 


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	vector<int> v1 = { 20,30,40,25,15 };

	// Converting vector into a heap
	// using make_heap()
	make_heap(v1.begin(), v1.end());

	// Displaying the maximum element of heap 
	// using front()

	cout << "The Maximum element of heap is : ";
	cout << v1.front() << endl;
	return 0;
}

