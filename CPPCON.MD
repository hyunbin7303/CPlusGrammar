# CPP Conference lecture note.


## CppCon 2017: Kate Gregory “10 Core Guidelines You Need to Start Using Now”
source : https://www.youtube.com/watch?v=XkDEzfpdcSg&t=20s      

#### Don't define a default constructor that only initializes data members; use in-class member initializers instead.
* Prefer in-class initializers to member initializers in constructors for constant initializers.

Change this one
```
class Simple
{
public:
  Simple() : a(1), b(2), c(3) {};
  Simple(int aa, int bb, int cc=-1) : a(aa), b(bb), c(cc) {}
  Simple(int aa) {a = aa; b=0; c=0;}
 private:
  int a;
  int b;
  int c;
};
```
into this
```
class Simple
{
public:
  Simple() = default;
  Simple(int aa, int bb, int cc) : a(aa), b(bb), c(cc) {}
  Simple(int aa) {}
 private:
  int a = -1;
  int b = -1;
  int c = -1;
};
  ```
#### Where there is a choice, prefer default arguments over overloading.
```
class Reactor
{
public:
  double Offset(double a, double b, double ff);
  double Offset(double a, double b);
};
double Reactor::Offset(double a, double b, double ff)
{
  return something;
}
double Reactor::Offset(double a, double b)
{
  return Offset(a,b,1.0);
}
```
Modify to this 
```
class Reactor
{
public:
  double Offset(double a, double b, double ff = 1.0);
 };
```

#### Keep the number of function arguments low
```
int area(int x1, int y1, int x2, int y2);
not this...

int area(Point p1, Point p2);
int a = area({1,1}, {2,2});
```
```
class Customer
{
  person details;
  Salesrep rep;
};
Customer(person p, Salesrep s);
```

#### Never transfer ownership by a raw pointer!
Not like this!
```
Policy* SetUpAndPrice(args)
{
  Policy *p = new Policy{...};
  ///....
  return p;
}
```
##### Alternatives to raw pointers
- return by value.
- Take by non-const reference and change it
- Return an appropriate smart pointer
- Use owner<> from GSL


#### To return multiple "out" values, prefer returning a tuple or struct.

```
int foo(int invalue, int& outValue)
{
  outValue = invalue * 2;
  return invalue *3;
}
int main()
{
  int num = 4;
  int ans = foo(5, number);
  return 0;
}
```

```
struct twoNumbers
{
  int value1;
  int value2;
};
twoNumbers fooStruct(in invalue)
{
  return twoNumbers{ invalue *2, invalue *3};
}
int main()
{
  int number, ans;
  twoNumbers result = fooStruct(6);
  number = result.value1;
  answer = result.value2;
  
}

```

#### std::optional

#### tuple, tie, structed bindings
```
std::tuple<int, int> fooTwo(int num)
{
  return std::make_tuple(num*2, num*3);
}
int main()
{
  int answer, number;
  std::tie(answer, number)= fooTwo(6);
  return 0;
}
int main()
{
  auto[answer, number] = fooTwo(6);
  return 0;
}

```
* Benefit - When parameters are passed by pointer or non-const ref, readers can assume they are in-out parameters.

#### Prefer to use class enums over "plain" enum
```
enum class Error { OK, FileNotFound, OutOfMemory };
enum class Ratings { Terrible, OK, Terrific};

Error result = Error::OK;
Ratings stars = Ratings::OK;
```

