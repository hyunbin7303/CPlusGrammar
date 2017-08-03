# CPlusGrammar 

This repository is used for studying *c++* grammar. 


- template specialization
- [LValue & RValue](#LValueRValue)
- [Perfect forwarding](#Perfectforwarding)



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

class Foo 











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

