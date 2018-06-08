// File : TypeTemplateParameter.cpp
// Programmar : Kevin Park
// Date		  : 2017 / 8 / 14



#include <iostream>
#include <string>	

// 1) A type template parameter with an optional name.
template <typename T> struct A{
	void func(T a)
	{
		std::cout << "SHOW struct A func :" << a << std::endl;
	}
};

// Same as A but using class
template <class something> class B {
private:
	std::string str;
public:
	void setString(std::string inputStr) {
		str = inputStr;
	}
	void show() {
		std::cout << "Show class B string : " << str << std::endl;
	}
};

// Default arguments for template parameters
// The set of default template arguments accumulates over 
// all declarations of a given template.
template <class Kevin, class Victor> class Ha;
template <class Kevin, class Victor = int> class Ha;
template <class Kevin = double, class Victor> class Ha;
template <class Kevin, class Victor> class Ha
{
public:
	Kevin x;
	Victor y;

	void show() {
		std::cout << x << std::endl;
		std::cout << y << std::endl;
	}
};



// Non-type template 
template <class Kevin, int size> class Na
{
	Kevin* x; // Should be pointer?
	static int arr[size];

public:

	Na() {};
	void show() {
		for (Kevin i = 0; i < size; i++)
		{
			x[i] = i;
			std::cout << x[i] << std::endl;
		}
		std::cout << "END OF SHOW FUNCTION " << std::endl;
	}
};


//Reference as a non-type template argument.
template <int a[5]> 
class foo {

public:
	void show() {
		for (int i = 0; i < 5; i++) {
			a[i] = i;
			std::cout << a[i] << std::endl;
		}
	}
};
int i;
const int z = 20;

template <class Kevin, Kevin value> constexpr Kevin constant = value;
constexpr auto const IntConstant42 = constant<int, 42>;


// Using Universal References

int main() {
	A<double> a;
	A<int> b;
	a.func(20.2);
	b.func(30);

	B<std::string> d;
	d.setString("HAHAHA");
	d.show();

	Ha<> ha;
	ha.x = 30;
	ha.y = 40;
	ha.show();

	
	// i should be declared as global.
	foo<&i> x;
	x.show();
	
	return 0;
}
