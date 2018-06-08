/*
File : Bug_CopyingOtherObject.cpp
Description : I made this file in order to acknowledge why problem was happened when copying other objects.
It also shows why we need operator overloading. If I don't have it, it shows error.
This can be one reason why we need copy constructor. 

*/


#include <new>
#include <iostream>
using namespace std;
class BugTest
{
private:
	int data1;
	int data2;
	int HowMany;
	int * ptr;

public:
	BugTest()
	{
		HowMany = data1 = data2 = 0;
		ptr = NULL;
	}

	~BugTest()
	{
		if (ptr != NULL)
		{
			delete[] ptr;
		}

	}


	void SetData(int input_data1, int input_data2)
	{
		data1 = input_data1;
		data2 = input_data2;
	}


	void setList(int count, int *arr)
	{
		if (ptr != NULL) // if memory exists.
		{
			delete[] ptr; // Deallocates storage previously allocated by a matching operator new.
		}
		HowMany = count; //  How many data are going to make 
		ptr = new int[HowMany]; 
		memcpy(ptr, arr, sizeof(int) * HowMany); // 
	}
	
	// Operator Overloading 
  // It is used when copying other objects using '='.
  // Return : Nothing. 
	void operator=(const BugTest &obj)
	{
		SetData(obj.data1, obj.data2);
		setList(obj.HowMany, obj.ptr);
	}
	
	void showInfo()
	{
		cout << "Data1 : " << data1 << " Data2 : " << data2 << endl;
		for (int i = 0; i < HowMany; i++)
		{
			cout << ptr[i] << endl;
		}
	}
};

int main()
{
	BugTest test1, test2;
	int arr[7] = { 1,2,3,4,5,6,7 };

	test1.SetData(30, 40);			
	test1.setList(7, arr);

  
	test2 = test1;  // Copying objects. 
	test2.showInfo();
	return 0;
}
