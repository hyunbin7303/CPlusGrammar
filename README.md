# CPlusGrammar 

This repository is used for studying *c++* grammar. 


- template specialization
- [LValue & RValue](#LValueRValue)
- [Perfect forwarding](#Perfectforwarding)
- [Using variants](#variants)
- [type template Parameter](#typeTemplateParameter)
- [NON-type template Parameter](#NONtypeTemplateParameter)
- [Template Type Deduction](#TemplateTypeDeduction)



This site was built using [GitHub Pages](https://pages.github.com/).
<hr/>

<a name="LValueRValue"></a>
## LValue & RValue

[Link to LValueRValue.cpp](https://github.com/hyunbin7303/CPlusGrammar/blob/master/LValueRValue.cpp)

An LValue referes to an object that persists beyond a single expression.
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

1) A type template parameter with an optional name - using ** typename **
2) Using class instead of typename ( same as 1))
3) A type template parameter with an optional name and a default
4) A type template parameter pack with an optional name

### Template template parameter



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
