#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <string>


using namespace std;


class ThreadWrapper
{
	thread & wt;
	ThreadWrapper(thread & tObj) : wt(tObj) {}
	~ThreadWrapper()// Destructor
	{
		if (wt.joinable())
		{
			wt.detach();
		}
	}

};


void func1()
{
	for (int i = 0; i < 10000; i++)
	{
		cout << " Func 1 value " << endl;
	}
}


int main()
{
	thread tObj(func1);
	ThreadWrapper twrapper(tObj);
	return 0;
}