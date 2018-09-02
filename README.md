# CPlusGrammer 

This repository is used for studying *c++* grammar. 

- [Call Back](#CallBack)
- [Passing Parameters as Const Reference](#ConstReference)
- [What is Non-static member function?](#Nonstaticmemberfunction)
- [template specialization](#TemplateSpecialization)
- [LValue & RValue](#LValueRValue)
- [Perfect forwarding](#Perfectforwarding)
- [Using variants](#variants)
- [type template Parameter](#typeTemplateParameter)
- [NON-type template Parameter](#NONtypeTemplateParameter)
- [Template Type Deduction](#TemplateTypeDeduction)
- [Deterministic & Nondeterministic algorithm](#deterministic)
- [Smart Pointer](#SmartPointer)





This site was built using [GitHub Pages](https://pages.github.com/).
<hr/>

<a name="CallBack"></a>
## Call Back
From http://thispointer.com/designing-callbacks-in-c-part-1-function-pointers/       
Callback is a function that we pass to another APIs as argument while calling them.
From https://stackoverflow.com/questions/2298242/callback-functions-in-c      
A callback is a callable accepted by a class or function, used to customize the current logic
depending on that callback.     
Reason - Why we use this is to write generic code which is independent from the logic in the 
called function and can be reused with different callbacks.      

It is normally used in the algorithm library. For instance like for_each, it applies an 
unaray callback to every item in a range of iterators.


<a name="ConstReference"></a>
## Passing Parameters as Const Reference         
source : http://www.learncpp.com/cpp-tutorial/73-passing-arguments-by-reference/       
### Limitation of pass by reference.
Non-const references can only reference non-const L-Values(e.g. non-const variables), so a reference parameter cannot accept an argument
 that is a const L-value or an R-Value.
* One drawbacks of pass by value is that all arguments passed by value are copied into the function parameters.

### Why we use this?
Passing class types by value is *expensive*, since the compiler have to do often:
* allocate a temporary local variable of the type.
* Copy the bytes of the argument to the temporary.
* Pass a pointer to the temporary into the function.

### When is the proper time we use this?
References allow the function to change the value of the argument. Sometimes, we just want to use the variable for read-only.
We can ensure that the function will not change the argument. 

### Advantages
* It enlists the compilers help in ensuring values that shouldn’t be changed aren’t changed 
* It tells the programmer that the function won’t change the value of the argument. This can help with debugging.
* You can’t pass a const argument to a non-const reference parameter. Using const parameters ensures you can pass both non-const and const arguments to the function.
* Const references can accept any type of argument, including l-values, const l-values, and r-values.



<hr/>
<a name="Nonstaticmemberfunction"></a>
## What is Non-static member function?            
http://en.cppreference.com/w/cpp/language/member_functions            
A non-static member function is a function that is declared in a member specification of a class without a static or friend specifier.


<a name="LValueRValue"></a>
## LValue & RValue

[Link to LValueRValue.cpp](https://github.com/hyunbin7303/CPlusGrammar/blob/master/LValueRValue.cpp)             

An LValue refers to an object that persists beyond a single expression.
  As an object that has a name. (All variables, including nonmodifiable(const variables)).
 
 An RValue is a temporary value that does not persist beyond the expression that uses it.
 
 
 information from : https://agop.me/post/perfect-forwarding-cpp-11.html
 ### RValue
 RValue references enable you to distinguish an LValue from an RValue.
 LValue references is a reference that binds to an RValue, like temporary object.
 
Why we need to do that?
-> **In order to avoid making an unnecessary copy.**

```
class Foo 
{
public :
      std::string member;
      Foo(const std::string& member) : member{member} {}
};
Foo foo{bar + baz}; 
```
bar+ baz creates a temporary std::string, the const std::string&member parameter
binds to that temporary, and then the temporary is copied to Foo::member.
By using an RValue reference, we can skip copying the temporary by moving it directly
into the member.

**Foo(std::string&& member): member{std::move(member)} {}**
....

bar+baz creates a temporary, the **std::string&& member parameter** binds to that temporary,
and we invoke Foo::emeber's move constructor with member{std::move(member)}.
(member parameter is not an RValue!) It is an LValue of type RValue reference.
use std::move(member) to cast the member parameter back to an RValue.(So we invoke std::string's std::string move constructor!)



```
class Kevin
{
private:
	std::string str;

public:
	Kevin(std::string something) : str{ std::move(str) } {}
};

```
Good thing about this code is that
CASE 1 : use RValue.
str's move constructor would be used.
After that, **Kevin::str**'s move constructor would be invoked.
RESULT : 0 copy, 2 moves.

CASE 2 : use LValue
str's copy constructor would in invoked.
After hat, Kevin::str's move constructor would be invoked.
RESULT : 1 copy, 1 move.










<hr/>



<a name="Perfectforwarding"></a>
## Perfect forwarding
information from : 
http://www.cppsamples.com/common-tasks/perfect-forwarding.html
Forward arguments of one function to another as if the wrapped function had been called directly.
Perfect forwarding allows us to preserver an argument's value category(LValue/ RValue) and const/volatile modifiers.
Perfect forwarding is performed in two steps. 
1) Receive a forwarding reference.
2) forward it using std::forward.
[Information about std::forward](#WhatIsForward)

Perfect forwarding allows us to write one function(or constructor)
and perfectly forward each parameter either as an RValue / LValue, depending on how it was passed in.

<hr/>

## using variants 
According to http://en.cppreference.com/w/cpp/utility/variant,
The class template std::variant represents a type-safe union. 
An instance of std::variant at any given time either holds a value of one of its alternative types,
or it holds no value. 

```
variant<int, string> v = 10;
int d = get<int>(v);
```
A variant is permitted to hold the same type more than once, and to hold differently cv-qualified versions of the same type. 

Tha basic difference between variant and union is that variant knows which type it store while union expects you to keep track of that externally. So if you try to access the wrong item in a variant, you will get an exception or nullptr.
By contrast, doing so with a union is merely undefined behaviour.

Union is a lower-level tool, but variant has machinery for doing visitation.
What is [visitation?](#visitation)

It might be used with std::get
### std::get
Reads the value of the variant given the index or the type. 

####  Return Value
Reference to the value stored in the variant.

### CV type qualifiers
http://en.cppreference.com/w/cpp/language/cv
For the type T(including incompete types), other than function type and reference type,





## Type template Parameter
<a name="typeTemplateParameter"></a>
From : http://en.cppreference.com/w/cpp/language/template_parameters      

1) A type template parameter with an optional name - using **typename**
2) Using class instead of typename ( same as 1))
3) A type template parameter with an optional name and a default
4) A type template parameter pack with an optional name


### Parameter Substitution in templates
e.g.


### Using Non-type template Parameter
The advantage of using this parameter is that the type of the corresponding non-type template argument deduced automatically.

- [NON-type template Parameter](#NONtypeTemplateParameter)

## Non-Type Template parameter

https://stackoverflow.com/questions/5687540/non-type-template-parameters        

A non-type template-parameter should have one of the following (optionally cv-qualified) types:
* Integral or enumeration type 
* Pointer to object or pointer to function.
* LValue reference to object or LValue reference to function.
* Pointer to member.
* std::nullptr_t

A non-type template argument provided within a template argument list is an expression whose value can be determined at compile time.
- const expressions, addresses of functions, objects with external linkage, addresses of static class members.
Also, string literals are objects with internal linkage, so cannot use them as template arguments.          
**Cannot Declare as a Floating point, class, or void type.**
Because Non-type template parameters are not **LValues**                

According to http://open-std.org/JTC1/SC22/WG21/docs/papers/2016/p0127r1.html         
## Using auto
The template parameter list syntax can be extended in a simple and natural way using the auto keyword to indicate that
the type of a value parameter is deduced at the point of instantiation. 


<a name="TemplateTypeDeduction"></a>
## (auto-related) Template Type Deduction

```
template<typename T>
void foo(paramType param);
foo(expr); // deduce T and paramType from expr
```
You are deducing two different things: 
T -> the deduced type.
ParamType -> Often different from T (e.g. const T&).
Because of deducing T, depends on form of the parameter declaration.
THree general cases :
1. ParamType is a reference or pointer, but not a universal reference.
2. ParamType is a universal reference.
3. ParamType is neither reference nor pointer.

### Non-URef refence / Pointer Parameters.
Type deduction very simple:
* If expr's type is a reference, ignore that.
* Pattern-match expr's type against ParamType to determinte T.

``` 
template<typename T>
void f(T& param);

int x = 30;		// int
const int zx = x; 	// copy of int
const int& ax = x;	// reference to const view of int
f(x); 			// T= int, param's type = int&
f(zx);			// T= const int, Param's type = const int&
f(ax);			// T = const int, Param's type = const int&
```
**Note: T not a reference**

### Non-URef Reference / Pointer Parameters
ParamType of const T& ==> T changes, but Param's type doesn't it:
```
template<typename T>
void foo(const T& param); // Reference const T? 

int x = 30; // int
const int zx  = x; // copy of int 
const int &ax = x; // reference to const view of int 
f(x); 			// T= int, param's type = const int&
f(zx);			// T= const int, Param's type = const int&
f(ax);			// T = const int, Param's type = const int&

```

```
template<typename T>
void foo(T* param); // param now a pointer. 

int x = 30; // int
const int *ax = &x; 	// pointer to const view of int 
f(&x); 			// T= int, param's type = const int*
f(ax);			// T= const int, Param's type = const int*
```
### Auto and Non-UReference / Pointer Variables       
```
auto& v1 = x; 	// v1's type = int& (auto = int)
auto& v2 = zx;  // v2's type = const int& (auto = const int)
auto& v3 = ax;	// v3's type = const int& (auto = const int)

const auto& v4 = x; // v4's type = const int& (auto = int)
const auto& v5 = zx; //v5's type = const int& (auto  = const int)
const auto& v6 = ax; //v6's type = const int& (auto = const int)
```

### Universal Reference         
https://www.youtube.com/watch?v=wQxj20X-tIU&t=587s       
```
template<typename T>
void foo(T&& param);
f(expr);
```
* If expr is LValue with deduced type E, T deduced as E&.
--> Reference-collapsing yeirds type E& for param. 

```
int x = 22;
const int cx = x;
const int& rx = x; 
f(x);		// x is LValue => T = int&, param's type = int&
f(cx);		// cx is LValue => T = const int&, param's type = const int&
f(rx); 		// rx is LValue => T = const int&, param's type = const int&
f(22); 		// x is Rvalue => No special handling; T = int, param's type is int&&

```


<hr/>

<a name="deterministic"></a>
## Deterministic & Nondeterministic algorithm            
non-deterministic algorithm - Same input, can display different behaviors on different runs.
A concurrent algorithm can perform differently on different runs due to a race condition.
Probabilistic algorithm.... random number generator.

When we say "Algorithm", it refers to a deterministic algorithm. 
nondeterministic algorithm represents a single path -> many paths.

<hr/>

## Smart Pointer
<a name="SmartPointer"></a>
FRom : https://msdn.microsoft.com/en-us/library/hh279674.aspx      
- <memory> header file.       
- RAII or Resource Acquisition Is Initialization programming idiom.      
To ensure that resource acquisition occurs at the same time that the object is initialized.    



### unique_ptr
- A smart pointer that owns and manages another object through a pointer and disposes of that object when the 
unique_ptr goes out of scope.       
- Cannot copy(since smart pointer deletes objects that already exist).

Only data member in unique_ptr is the encapsulated pointer, which is that unique_ptr
is exactly the same size as that pointer, either four bytes or eight bytes.










<hr/>

## Appendix
<a name="WhatIsForward"></a>
### std::forward
According to http://en.cppreference.com/w/cpp/utility/forward,
Forwards LValues as either LValues or as RValues, depending on T.
ex)
```
template<class T>
void wrapper(T&& arg)
{   // arg is always LValue
    foo(std::forward<t>(arg));  // Forward as LValue or as RValue, depending on T
}
```
**Note: T not a pointer!**





### constexpr specifier      
http://en.cppreference.com/w/cpp/language/constexpr         
It declares that it is possible to evaluate the value of the function or variable at compile time.        
Such variables and functions can then be used where only compile time constant expressions are allowed.
This specifier used in a function or static member variable declaration implies inline. ( c++ 17)



### Forward declaration
source from : https://en.wikipedia.org/wiki/Forward_declaration
In computer programming, a forward declaration is a decaration of an identifier for which the programmer has not yet given a complete definition. It is required for a compiler to know certain properties of an identifier(size of memory allocation, data type for type checking, such as type signature of functions), but not other details, like the particular value it holds in case of variables or constants or definition.

```
void kevinPark(int);
```
The line above represents a forward declaration of a function and is the function's prototype. After processing this declaration, the compiler would allow the program code to refer to the entity kevinPark in the rest of the program.

In c++, classes and structs can be forward-declared like this:
```
class MyClass;
struct MyStruct;
```
Classes can be forward-declared if you only need to use the pointer-to-that-class type(since all object pointers are the same size)
This is useful inside class definitions, if a class contains a member that is a pointer(or a reference) to another class.
** Forward-declaration ** is used to avoid unnecessary coupling which help reducing compilation time by reducing the number of header inclusion.
 HOW??? - reducing the number of files opened by #include, reducing the volume of the pre-processed filed.
 
 
 
 ### Variadic templates 
 source from : http://eli.thegreenplace.net/2014/variadic-templates-in-c/
 Variadic templates can be used for ....  
 
 
 ### Union 
https://docs.microsoft.com/en-us/cpp/cpp/unions
A Union is a user-defined type in which all members share the same memory location. It means that at any given time aunion can contain no more than one object from its list of members, it also means that no matter how many members a union has, it always uses only enough memory to store the largest member.
 
 
 
 ### Visitation 
 


### std::move
http://www.cplusplus.com/reference/utility/move/
It returns an RValue reference to arg.
This is helpful function to force move semantics on values, even if they have a name: Directly using the returned value causes argument to be considered as RValue.

https://mbevin.wordpress.com/2012/11/20/move-semantics/
When we are passing an object to an function(or when we are returning an object from a function), it is better to do a move(rather than a copy) if:
* The object is an RValue
* The object's class defines the special member move functions.

What happen is that, data is removed from the old object when 'move' happens, and it replaced into a new object.


### std::for_each
https://stackoverflow.com/questions/2047414/advantages-of-stdfor-each-over-for-loop      
Advantages:
1. For_each allows people to write an algorithm on top of for_each that works with any iterator.
2. For_each reduces the chance of typing bugs.
3. For_each is more generic, so it enables me to iterate over any type of container by passing in the being/end iteroators.

http://www.fluentcpp.com/2017/01/05/the-importance-of-knowing-stl-algorithms/        
Specific reason foor_each is used : when performing side effects.
For_each should be used to modify the elements of the collection it is applied on, or to perform side effectts on a more general sense, like sending information to a logger or to an external service.

IF You rather need to count the number of times a value is present is a collection, use std::count.
IF You rather need to know if there is at least one element satisfying a predicate, use std::all_of.
IF you rather need to know whether a collection is a permutation of another one, use std::_permutation.
