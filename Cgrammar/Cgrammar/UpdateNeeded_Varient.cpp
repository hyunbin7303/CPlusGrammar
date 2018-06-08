/*
#include <iostream>
#include <variant>
#include <string>

int main()
{
	std::variant<int, char> v = 'a';
	int d = std::get<char>(v);

	std::cout << d << std::endl;

	return 0;
}
*/

/*
#include <variant>
#include <string>
#include <iostream>
#include <iostream>

int main()
{
	std::variant<int, float> v{ 12 }, w;
	int i = std::get<int>(v);
	w = std::get<int>(v);
//	w = std::get<0>(v); // same effect as the previous line.

	try {
		std::get<float>(w);
	}
	catch (std::bad_variant_access&) {}	
	std::cout << w << std::endl;
	
	return 0;
}
*/
/*
	
#include <variant>
#include <iostream>
#include <type_traits>
#include <iomanip>
#include <vector>
#include <string>
template<class T> struct always_false : std::false_type {};
using var_t = std::variant<int, long, double, std::string>;
int main() {
	std::vector<var_t> vec = { 10,151,1.5, "HELLO WORLD" };
	for (auto v : vec)
	{
		std::visit([](auto&& arg) {std::cout << arg; }, v);
		var_t w = std::visit([](auto&& arg) -> var_t {return arg + arg; }, v);

	}
	return 0;
}*/


/*
#include <variant>
#include <string>
#include <cassert>
#include <iostream>
using namespace std::literals;
using my_varint = std::variant<int, float, double>;

struct printer
{
void operator()(int x)	 { std::cout << x << "i\n"; }
void operator()(float x) { std::cout << x << "f\n"; }
void operator()(double x) { std::cout << x << "d\n"; }
};

int main()
{

my_varint v0{ 20.f };

// Prints "20f"
std::visit(printer{}, v0);

return 0;
}
*/


#include <variant>
#include <iostream>

int main()
{
	std::variant<int, float> v, w;
	v = 12;
	int i = std::get<int>(v);
	w = std::get<int>(v);
	w = std::get<0>(v);

	std::cout << i << std::endl;
	return 0;
}


/*
#include <variant>
#include <iostream>


struct foo_float {
int operator()(float a){ return a;}
};
struct foo_char {
char operator()(char a) { return a;}
};

struct foo : foo_float, foo_char
{
using foo_float::operator();
using foo_char::operator();
};

int main()
{
auto x0 = foo{}(0.f);
auto x1 = foo{}('a');

std::cout << x0 << std::endl;
std::cout << x1 << std::endl;

return 0;
}
*/


