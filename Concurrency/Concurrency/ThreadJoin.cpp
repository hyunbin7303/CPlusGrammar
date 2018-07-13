#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
using namespace std;


void func1(unsigned int i)
{
	cout << "ID VALUE : " << i << "\n";
}
int main()
{
	vector<thread> t_vec;
	for (int i = 0; i < 10; i++)
	{
		t_vec.push_back(thread(func1,i));
	}
	cout << "WAITINGGGGGGGGG " << endl;
	for_each(t_vec.begin(), t_vec.end(), mem_fn(&std::thread::join));
	cout << "EXITING MAIN THREAD" << endl;
	system("pause");
	return 0;
}