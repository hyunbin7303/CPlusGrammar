#include <iostream>
#include <vector>
#include <thread>
using namespace std;


int main()
{
	vector<thread> vecOfThread; // Vector of Threads.
	function <void()> func = []() 
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "FROM Thread ID : " << std::this_thread::get_id() << endl;
	};

	vecOfThread.push_back(thread(func)); // thread object to vector? 

	thread t1(func);
	thread t2(func);
	vecOfThread.push_back(move(t1));
	vecOfThread.push_back(move(t2));
	thread t3(func);
	if (vecOfThread[1].joinable())
	{
		vecOfThread[1].join();
	}

	system("pause");
}