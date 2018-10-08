# Creational 
## Abstract Factory

Abstract factory pattern has creational purpose and provides an interface for 
creating families of related or dependent objects without specifying their 
concrete classes. Pattern applies to object and deal with object relationships, 
which are more dynamic. In contrast to Factory Method, Abstract Factory pattern
produces family of types that are related, ie. it has more than one method of 
types it produces.


### When to use

* a system should be independent of how its products are created, composed, and represented
* a system should be configured with one of multiple families of products
* a family of related product objects is designed to be used together
* you want to provide a class library of products, and you want to reveal just their interfaces, not their implementations

## Builder

Builder pattern has creational purpose and separates the construction of a complex object 
from its representation so that the same construction process can create different 
representations. It is object pattern, ie. relationships can be changed at run-time
and are more dynamic. Often is used for building composite structures but constructing
objects requires more domain knowledge of the client than using a Factory.

### When to use

* the algorithm for creating a object should be independent of the parts and how they're assembled
* the construction process must allow different representations for the object that's constructed  

## Factory Method

Define an interface for creating an object, but let subclasses decide which class to instantiate. 
Factory Method lets a class defer instantiation to subclasses. The pattern has creational purpose
and applies to classes where deals with relationships through inheritence ie. they are static-fixed 
at compile time. In contrast to Abstract Factory, Factory Method contain method to produce only one
type of product.  

### When to use

* a class cant anticipate the class of objects it must create
* a class wants its subclasses to specify the objects it creates
* classes delegate responsibility to one of several helper subclasses, and you want to localize the knowledge of which helper subclass is the delegate 

## Prototype

Specify the kinds of objects to create using a prototypical instance, and create 
new objects by copying this prototype. Pattern has creational purpose and deals 
with object relationships, which are more dynamic. The pattern hides the complexities
of making new instances from the client.

### When to use

* when the classes to instantiate are specified at run-time
* to avoid building a class hierarchy of factories that parallels the class hierarchy of products
* when instances of a class can have one of only a few different combinations of state 

## Singleton

Ensure a class only has one instance, and provide a global point of access to it.
Pattern has creational purpose and deals with object relationships, which are more 
dynamic. The Singleton is often used as a part another design patterns (see [Façade] 
and [Flyweight]). 

### When to use

* there must be exactly one instance of a class, and it must be accessible to clients from a well-known access point
* when the sole instance should be extensible by subclassing, and clients should be able to use an extended instance without modifying their code

[Façade]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/facade
[Flyweight]: https://github.com/JakubVojvoda/design-patterns-cpp/tree/master/flyweight
