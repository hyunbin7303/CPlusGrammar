#include <iostream>
#include <string>
using namespace std;

template <class A>
std::string GetValue();

class A
{
private:
	int num1;
	int num2;

};

class B
{
private:

};

template<class KEVIN>
std::string GetSomeValue();

template<>
std::string GetSomeValue<A>()
{
	return "RETURNING GETSOME VALUE A";
}
template<>
std::string GetSomeValue<B>()
{
	return "RETURNING GETSOME VALUE B";
}

template<class A>
std::string GetValue()
{
	return "[CLASS A GetValue]";
}

int main()
{
	cout << GetValue<A>() << endl;
	cout << GetValue<B>() << endl;
	cout << GetSomeValue<A>() << endl;
	cout << GetSomeValue<B>() << endl;

	system("pause");
	return 0;
}