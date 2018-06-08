#include <iostream>
#include <thread>

void DisplayMainThread();

void Thread_Testing()
{
	for (int i = 0; i < 1000; i++)
	{
		std::cout << i;
		std::cout << " Thread function Testing" << std::endl;
	}
}



class ThreadTest
{
public:
	void operator()()
	{
		for (int i = 0; i < 1000; i++)
		{
			std::cout << i;
			std::cout << " Thread Class Testing " << std::endl;
		}
	}
};
int main()
{
	int chooseOption = 3;
	//std::thread threadObj(Thread_Testing);
	//std::thread threadObj2((ThreadTest()));

	std::thread threadObj3([] {
		for (int i = 0; i < 1000; i++)
		{
			std::cout << "Display From Lambda " << std::endl;
		}
	});
	
	switch (chooseOption)
	{
	case 1: 
	//	std::cout << "Thread Functor Try!" << std::endl;
		DisplayMainThread();
		//threadObj.join();
		break;
	case 2:
		DisplayMainThread();
		//threadObj2.join();
		break;
	case 3:
		DisplayMainThread();
		threadObj3.join();
		break;
	default:
		std::cout << "Default" << std::endl;
		break;
	}
	std::cout << "Exit of Main function " << std::endl;
	system("pause");
	return 0;
}

void DisplayMainThread()
{
	for (int i = 0; i < 1000; i++)
	{
		std::cout << i;
		std::cout << " Display From MainThread " << std::endl;
	}
}
