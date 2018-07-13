#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <string>
using namespace std;

mutex mux;
void Func()
{
	cout << " FUNC 1 " << endl;
	for (int i = 0; i < 100; i++)
	{
		cout << "THREAD FUNC 1 number - " << i << endl;
	}
}
void shared_cout(string msg, int ID)
{
	mux.lock();
	cout << msg << " : " << ID << endl;
	mux.unlock();
}
void thread_func()
{
	for (int i = -100; i < 0; i++)
	{
		shared_cout("Thread Func", i);
	}
}



int main()
{
	thread t1(&thread_func);
	for (int i = 100; i > 0; i--)
	{
		shared_cout("MAIN THREAD :	", i);
	}
	
	t1.join();
	system("pause");
	return 0;
}

