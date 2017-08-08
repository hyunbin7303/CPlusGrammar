# CPlusGrammar 

This repository is used for studying *c++* grammar. 


- template specialization
- [LValue & RValue](#LValueRValue)
- [Perfect forwarding](#Perfectforwarding)
- [Using variants](#variants)



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

RValue references mark binding 


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

It might be used with std::get
### std::get
Reads the value of the variant given the index or the type. 

####  Return Value
Reference to the value stored in the variant.

### CV type qualifiers
http://en.cppreference.com/w/cpp/language/cv
For the type T(including incompete types), other than function type and reference type,










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
 
 
 
 
 
