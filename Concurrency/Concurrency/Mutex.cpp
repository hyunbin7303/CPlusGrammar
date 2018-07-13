// mutex example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include <queue>
//
//class CriticalRegion
//{
//public:
//	std::mutex mtx;           // mutex for critical section
//};
//

std::mutex mtx;           // mutex for critical section




void print_block(int n, char c) {
	// critical section (exclusive access to std::cout signaled by locking mtx):
//	CriticalRegion cri;
	
	mtx.lock();
	for (int i = 0; i<n; ++i) { std::cout << c; }
	std::cout << '\n';
	mtx.unlock();
}

int main()
{
	std::thread th1(print_block, 50, '*');
	std::thread th2(print_block, 50, '$');

	th1.join();
	th2.join();


	system("pause");
	return 0;
}