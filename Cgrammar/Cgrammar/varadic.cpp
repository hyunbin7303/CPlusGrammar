/*
A template parameter pack is a template parameter that accepts 
zero or more template arguments(non-types, types, or templates).
A funciton parameter pack is a function parameter that accepts zero
or more function arguments. 

A template with at least one parameter pack is called a varadic template. 


A variadic class template can be called with any number of function arguments
(the template arguments are deduced through template argument deduction):

A variadic class template can be instantiated with any number of template arguments.
A variadic function template can be called with any number of function arguments.





#include <iostream>
using namespace std;

int f(int a) { return a + 1; }


template <typename ...Types>
void goo(Types ... args)
{
	cout << "Goo" << endl;
}

void hoo(int a, int b, int c)
{
	cout << "Hoo " << a << b << c << endl;
}

template <typename ... Types>
void foo(Types ... args)
{
	// 1. sizeof ...() keyword
	// In here, sizeof... is used for counting numbers of parameter pack.
	cout << sizeof...(Types) << endl;
	cout << sizeof...(args) << endl;


	// 2. Sending parameter pack to other function.
	goo(args...);

	// 3. Pack expansion - parameter pack 
	hoo(args...);
	hoo(f(args)...); // <hoof(1), f(2), f(3))
}



int main(int argc, char* argv[])
{
	foo(1, 2, 3);
	return 0;
}

*/


/*
#include <iostream>

using namespace std;


static int n = 0;

template <typename T, typename ...Types>
void Goo(T a, Types ... args)
{
	++n;
	
	// typeid used where the dynamic type of a polymorphic object must be known and for
	// static type identification. 1
	cout << n << ": " << typeid(T).name() << " : " << a << endl; 
	Goo(args...);	
}
void Goo()
{ cout << "Goo Exit! " << endl; }
int main(int argc, char *argv[])
{
	Goo(1, 3.4, "aa", 5, "fsfsfs");

	return 0;
}*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Add
{
	T x;
public:
	Add(T xx) : x(xx) {}
	void operator()(T& e) const { e += x; }
};


template <typename T>
class PrintElement
{
public:
	void operator()(T& elm) const { cout << elm << ' '; }
};


int main()
{
	int size = 5;
	vector <int> v;
	for (int i = 0; i < size; i++)
	{
		v.push_back(i);
	}
	PrintElement<int> print_it;
	cout << "Haha" << endl;
	for_each(v.begin(), v.end(), print_it); 
	cout << "Haha" <<endl;
	for_each(v.begin(), v.end(), Add<int>(10)); 
	cout << "nana" << endl;
	for_each(v.begin(), v.end(), print_it); cout << endl;
	for_each(v.begin(), v.end(), Add<int>(*v.begin()));
	for_each(v.begin(), v.end(), print_it);
}
