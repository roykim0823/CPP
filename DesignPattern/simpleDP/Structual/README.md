# Structural

## Adapter

Convert the interface of a class into another interface the clients expect.
Adapter lets classes work together that couldn't otherwise because of
incompatible interfaces, ie. allows to use a client with an incompatible 
interface by an Adapter that does the conversion. 

Adapter has structural purpose and can be applied on classes and also on object. 
1. A class adapter uses multiple inheritance to adapt one interface to another 
2. The object adapter uses object composition to combine classes with different interfaces.

### When to use

* you want to use an existing class, and its interface does not match the one you need
* you want to create a reusable class that cooperates with classes that don't necessarily have compatible interfaces

## Bridge (PIMPL)

Decouple an abstraction from its implementation so that the two can vary independently. 
Bridge pattern has structural purpose and applies to objects, so it deals with the composition of objects. 

### When to use

* you want to avoid a permanent binding between an abstraction and its implementation
* both the abstractions and their implementations should be extensible by subclassing
* changes in the implementation of an abstraction should have no impact on clients
* you want to hide the implementation of an abstraction completely from clients

## Composite

Compose objects into tree structures to represent part-whole hierarchies. 
Composite lets clients treat individual objects and compositions of objects uniformly. 
The pattern has structural purpose and applies to objects.

### When to use

* you want to represent part-whole hierarchies of objects
* you want clients to be able to ignore the difference between compositions of objects and individual objects

## Decorator

Attach additional responsibilities to an object dynamically. Decorators
provide a flexible alternative to subclassing for extending functionality.
The pattern has structural purpose and applies to objects.

### When to use

* to add responsibilities to individual objects dynamically and transparently, that is, without affecting other objects
* for responsibilities that can be withdrawn
* when extension by subclassing is impractical

## Façade

Provide a unified interface to a set of interfaces in a subsystem. Facade
defines a higher-level interface that makes the subsystem easier to use. 
The pattern has structural purpose and applies to objects.

### When to use

* you want to provide a simple interface to a complex subsystem
* there are many dependencies between clients and the implementation classes of an abstraction
* you want to layer your subsystems, use a facade to define an entry point to each subsystem level 

## Flyweight

Flyweight pattern has has structural purpose, applies to objects and uses sharing to support 
large numbers of fine-grained objects efficiently. The pattern can be used to reduce 
memory usage when you need to create a large number of similar objects.

### When to use

* when one instance of a class can be used to provide many "virtual instances"
* when all of the following are true
 * an application uses a large number of objects
 * storage costs are high because of the sheer quantity of objects
 * most object state can be made extrinsic
 * many groups of objects may be replaced by relatively few shared objects once extrinsic state is removed
 * the application doesn't depend on object identity 
 
## Proxy

Proxy pattern provides a surrogate or placeholder for another object to control access to it.
The pattern has structural purpose and applies to objects. 

### When to use

* whenever there is a need for a more versatile or sophisticated reference to an object than a simple pointer
