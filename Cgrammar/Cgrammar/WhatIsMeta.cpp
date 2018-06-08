
/*
#include <iostream>
template <typename T1, typename T2>
struct is_same
{
	enum _value_ {value = false};	
};

template <typename T>
struct is_same<T, T>
{
	enum _value_{value = true};
};

int main(void)
{
	using std::cout;
	using std::endl;


	cout << is_same<int, float>::value << endl;
	cout << is_same<int, long>::value << endl;
	cout << is_same<int, int>::value << endl;


	return 0;
}*/

/*
#include <iostream>
#include <type_traits>
#include <cstdint>

void print_separator()
{
	std::cout << "------- \n";
}
int main()
{
	std::cout << std::boolalpha;

	std::cout << std::is_same<int, int32_t>::value		<< '\n'; // true
	std::cout << std::is_same<int, int64_t>::value		<< '\n'; // false 
	std::cout << std::is_same<float, int32_t>::value	<< '\n'; // false 

	print_separator();

	std::cout << std::is_same<int, int>::value			<< "\n";
	std::cout << std::is_same<int, unsigned int>::value << "\n";
	std::cout << std::is_same<int, signed int>::value	<< "\n";

	print_separator();

	std::cout << std::is_same<char, char>::value			<< "\n";
	std::cout << std::is_same<char, unsigned char>::value	<< "\n";
	std::cout << std::is_same<char, signed char>::value		<< "\n";
}*/

/*

#include <iostream>

struct true_type {enum _value_ {value = true}; };
struct false_type {enum _value_ {value = false}; };

template <typename T1, typename T2>
struct is_same : false_type {};
template <typename T>
struct is_same<T, T> : true_type {};


template <typename T>
struct is_void : is_same<T, void> {};
template <typename T>
struct is_null_pointer : is_same<T, std::nullptr_t> { };

int main(void)
{
	using std::cout;
	using std::endl;

	cout << "is_void  " << endl;
	cout << is_void<int>::value << endl;
	cout << is_void<void>::value << endl;
	cout << is_void<const void>::value << endl;

	cout << "is_nullptr" << endl;
	cout << is_null_pointer<int*>::value << endl;
	cout << is_null_pointer<std::nullptr_t>::value << endl;
	cout << is_null_pointer<decltype(nullptr)>::value << endl;
	cout << is_null_pointer<const std::nullptr_t>::value << endl;

}
*/


#include <iostream>
#include <type_traits>

int main()
{
	std::cout << std::boolalpha
		<< std::is_null_pointer<decltype(nullptr)>::value << ' '
		<< std::is_null_pointer<int *>::value << '\n'
		<< std::is_pointer<decltype(nullptr)>::value << ' '
		<< std::is_pointer<int *>::value << '\n';
}


