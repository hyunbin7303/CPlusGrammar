// ThreadPractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>	
#include <thread>
#include <vector>
#include <algorithm>
using namespace std;
void thread_Prac01(int & value)
{
	cout << "Hello world. this is thread 1." << endl;
	cout << "Value is : " << value++ << endl;
}
void thread_Prac02(int value2, int value3)
{
	cout << "Check. Thread -02 " << value2 << endl;
	cout << "Value 3 Check. " << value3 << endl;
}
int main()
{
	int localValue = 100;
	// Invoke the function 
	thread t1(thread_Prac01, ref(localValue)); // passing by reference 
	t1.join();

	cout << "Value in the thread " << localValue << endl;
	int num = 10, num2 = 20;
	thread t2(thread_Prac02, num, num2);
	t2.join();

	// Using Lambda
	int num3 = 30;
	thread t3{ [](int& num3)
	{
		cout << "Thread Lambda is so fun!! " << endl;
		cout << "Value check" << num3++ << endl;
	}, ref(num3) };

	t3.join();
	cout << "Num3 check(Used lambda) : " << num3 << endl;
	cout << " ------------------------------------" << endl;
	vector<thread> thread_Vector;
	for (int i = 0; i < 10; i++)
	{
		thread_Vector.push_back(thread([]()
		{
			cout << "Thread Function \n";
		}));
	}
	cout << "checking vector thread! " << endl;
	for_each(thread_Vector.begin(), thread_Vector.end(), [](thread &t)
	{
		t.join();
	});
	return 0;
}

