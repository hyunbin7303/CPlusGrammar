
#include <vector>
#include <iostream>
#include <thread>
#include <algorithm>
using namespace std;

void Func1(unsigned id)
{
	cout << "ID value is " << id << endl;
}

void foo()
{
	vector<thread> t;
	for (unsigned i = 0; i < 10; i++)
	{
		t.push_back(thread(Func1, i)); // Spawn threads. 
	}
	for_each(t.begin(), t.end(), mem_fn(&thread::join)); // Call join on each thread in turn.
}


int main()
{




}