



// RValue
/*

Rvalue references enable you to distinguish an lvalue from an rvalue. 
Lvalue references and rvalue references are syntactically and semantically similar, 
but they follow somewhat different rules. For more information about lvalues and rvalues, 
see Lvalues and Rvalues. For more information about lvalue references, see Lvalue Reference Declarator: &.

Rvalue references support the implementation of move sematics,
which can significantly increase the performance of your applications.
Move semmantics enables you to write code that transfers resources
(such as dynamically allocated memory) from one object to another.

Move semantics works because it enables resources to be transferred from 
temporary objects that  cannot be referenced elsewhere in the program. 



*/

//
//#include <iostream>
//using namespace std;
//
//class MemoryBlock
//{
//private:
//	int a;
//	int b;
//public:
//	void setA(int seta)
//	{
//		a = seta;
//	}
//	void setB(int setb)
//	{
//		b = setb;
//	}
//};
//
//void g(const MemoryBlock&)
//{
//	cout << "In g(const MemoryBlock&). " << endl;
//}
//void g(MemoryBlock&&)
//{
//	cout << "In g(memoryBlock)." << endl;
//}
//
//
//int main()
//{
//	MemoryBlock block;
//	g(block); 
//	g(static_cast<MemoryBlock&&> (block));
//	return 0;
//}


#include <iostream>
#include <string>
using namespace std;

template<typename T> struct S;
// The following structures specialize S by LValue reference (T&),
// const Lvalue reference (const T&), 
// RValue reference (T&&), and const Rvalue reference (const T&&).
// Each structure provides a print method that prints the type of the
// structure and its parameter.


template<typename T> struct S<T&>
{
	static void print(T& t)
	{
		cout << "print<T&>: " << t << endl;

	}
};

template<typename T> struct S<const T&>
{
	static void print(const T& t)
	{
		cout << "print<const T&>: " << t << endl;
	}
};


template<typename T> struct S<T&&>
{
	static void print(T&& t)
	{
		cout << "print<T&&>: " << t << endl;
	}
};

template<typename T> struct S<const T&&>
{
	static void print(const T&& t)
	{
		cout << "print<const T&&>: " << t << endl;
	}
};


// This func forwards its parameter to a specialized version of the S type.
template <typename T> void print_type_and_value(T&& t)
{
	S<T&&>::print(forward<T>(t));
}

const string fourth()
{
	return string("fourth");
}

int main()
{
	string s1("first");
	print_type_and_value(s1);
	const string s2("second");
	print_type_and_value(s2);

	// The following call resolves to:  
	// print_type_and_value<string&&>(string&& t)  
	print_type_and_value(string("third"));

	// The following call resolves to:  
	// print_type_and_value<const string&&>(const string&& t)  
	print_type_and_value(fourth());
	return 0;
}

