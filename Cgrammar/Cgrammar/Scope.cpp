#include <iostream>

int Kevin::num = 20;
namespace Kevin2
{
	int numCheck = 50;
}
class Kevin
{
public:
	static int num;  // This is Scope of Kevin...
	void func();

};
void Kevin::func()
{
	std::cout << "Show result " << std::endl;
}
char haha = 'X'; // global variable
class A
{
public:
	int a;
	A()
	{
		std::cout << "CLass A Cons " << std::endl;
	}
	~A()
	{
		std::cout << "Destructor A " << std::endl;
	}
};
class BetterKevin
{
private:
	A * m_Aptr;
public:
	BetterKevin(A* newA) : m_Aptr(newA) {}
	~BetterKevin() { delete m_Aptr; }
};

int main()
{
	std::cout << Kevin::num << std::endl;
	int a = Kevin2::numCheck;
	std::cout << a << std::endl;
	char haha = 'Y';
	std::cout << "Call global variable normally : " << haha << std::endl; // Result : Y
	std::cout << "Call global variable with scope : " << ::haha << std::endl; // Result : X
	std::cout << "Two way for checking scope for stack based variable. " << std::endl;
	{
		A check;
	}
	std::cout << "Checking scope for heap based variable. " << std::endl;
	{
		A* aHeap = new A();
		aHeap->~A();
	}
	std::cout << "But I can do like this too~! " << std::endl;
	{
		BetterKevin bk = new A();
	}
	system("pause");
	return 0;
}

