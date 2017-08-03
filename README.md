# CPlusGrammar 

This repository is used for studying *c++* grammar. 


- template specialization
- [LValue & RValue](#LValueRValue)

<a name="there_you_go"></a>Take me there

This site was built using [GitHub Pages](https://pages.github.com/).
<hr/>

## LValue & RValue<a name="LValueRValue">

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
color: "#B9D9FF" Foo foo{bar + baz}; 
```
bar+ baz creates a temporary std::string, the const std::string&member parameter
binds to that temporary, and then the temporary is copied to Foo::member.
By using an RValue reference, we can skip copying the temporary by moving it directly
into the member.

Foo(std::string&& member): member{std::move(member)} {}
....

bar+baz creates a temporary, the std::string&& member parameter binds to that temporary,
and we invoke Foo::emeber's move constructor with member{std::move(member)}.





<hr/>

