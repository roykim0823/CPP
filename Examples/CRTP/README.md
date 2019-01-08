### CRTP
The Curiously Recurring Template Pattern (CRTP) is a C++ idiom whose name was coined by James Coplien in 1995, in early C++ template code.

The “C” in CRTP made it travel the years in the C++ community by being this: a Curiosity. We often find definitions of what CRTP is, and it is indeed an intriguing construct.

## What CRTP is
The CRTP consists in:
* inheriting from a template class,
* use the derived class itself as a template parameter of the base class.
This is what it looks like in code:
``` 
template <typename T>
class Base
{
        ...
};

class Derived : public Base<Derived>
{
        ...
};
```

The purpose of doing this is using the derived class in the base class. From the perspective of the base object, the derived object is itself, but downcasted. Therefore the base class can access the derived class by static_casting itself into the derived class.

```
template <typename T>
class Base
{
public:
	void doSomething()
  	{
  		T& derived = static_cast<T&>(*this);
  		use derived...
  	}
};
```

Note that contrary to typical casts to derived class, we don’t use dynamic_cast here. A dynamic_cast is used when you want to make sure at run-time that the derived class you are casting into is the correct one. But here we don’t need this guarantee: the Base class is designed to be inherited from by its template parameter, and by nothing else. Therefore it takes this as an assumption, and a static_cast is enough.

## What could go wrong
If two classes happen to derive from the same CRTP base class we likely get to undefined behaviour when the CRTP will try to use the wrong class:
```
class Derived1 : public Base<Derived1>
{
        ...
};
 
class Derived2 : public Base<Derived1> // bug in this line of code
{
        ...
};
```
There is a solution to prevent this, that has been proposed by Marek Kurdej in the comments section. It consists in adding a private constructor in the base class, and making the base class friend with the templated class:
```
template <typename T>
class Base
{
public:
	// ...
private:
	Base(){};
	friend T;
};
```
Indeed, the constructors of the derived class have to call the constructor of the base class (even if you don’t write it explicitly in the code, the compiler will do his best to do it for you). Since the constructor in the base class is private, no one can access it except the friend classes. And the only friend class is… the template class! So if the derived class is different from the template class, the code doesn’t compile. Neat, right?

Another risk with CRTP is that methods in the derived class will hide methods from the base class with the same name. As explained in Effective C++ Item 33, the reason for that is that these methods are not virtual. Therefore you want to be careful not to have identical names in the base and derived classes:

```
class Derived : public Base<Derived>
{
public:
	void doSomething(); // oops this hides the doSomething methods from the base class !
}
```
The first time I was shown CRTP my initial reaction was: “wait, I didn’t get it”. Then I saw it a couple of other times and I got it. So if you didn’t get how it works, just re-read section 1 a couple of times, and that should do it (if it doesn’t just get in touch and I’ll be happy to talk with you about it).

To tell you the truth, I started by writing a huge blog post about CRTP, which would have been daunting to read completely I think. For that reason I decided to split it up into several logical parts, which constitute the episodes of this series. This post was relatively short, but was necessary to put the basics in place.

### What the CRTP can bring to your code
there are several ways the CRTP can be useful. Here I am presenting the one that I see most in code, Adding Functionality, and another one that is interesting but that I don’t encounter as often: creating Static Interfaces.

## Who’s Your Interface Now?
A interesting point to note is that, although the CRTP uses inheritance, its usage of it does not have the same meaning as other cases of inheritance.

In general, a class deriving from another class expresses that the derived class somehow conceptually “is a” base class. The purpose is to use the base class in generic code, and to redirect calls to the base class over to code in the derived class.

With the CRTP the situation is radically different. The derived class does not express the fact it “is a” base class. Rather, it expands its interface by inherting from the base class, in order to add more functionality. In this case it makes sense to use the derived class directly, and to never use the base class (which is true for this usage of the CRTP, but not the one described below on static interfaces).

Therefore the base class is not the interface, and the derived class is not the implementation. Rather, it is the other way around: the base class uses the derived class methods (such as getValue and setValue). In this regard, the derived class offers an interface to the base class. This illustrates again the fact that inheritance in the context of the CRTP can express quite a different thing from classical inheritance.

## Static Interfaces
In static interfaces, the base class does represent the interface and the derived one does represent the implementation, as usual with polymorphism. But the difference with traditional polymorphism is that there is no virtual involved and all calls are resolved during compilation.
