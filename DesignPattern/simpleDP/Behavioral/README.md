## Chain of Responsibility

Chain of Responsibility pattern avoids coupling the sender of a request to its receiver 
by giving more than one object a chance to handle the request. The pattern chains 
the receiving objects and passes the request along the chain until an object handles it. 
It has a behavioral purpose and deals with relationships between objects. 

### When to use

* more than one object may handle a request, and the handler should be ascertained automatically
* you want to issue a request to one of several objects without specifying the receiver explicitly
* the set of objects that can handle a request should be specified dynamically

## Command

Command pattern encapsulates a request as an object, thereby letting you parameterize
clients with different requests, queue or log requests, and supports undoable
operations. The pattern has a behavioral purpose and deals with relationships between objects. 

### When to use

* want to parameterize objects by an action to perform
* want to specify, queue, and execute requests at different times
* support undo
* support logging changes so that they can be reapplied in case of a system crash
* structure a system around high-level operations built on primitives operations

## Interpreter

Given a language, the pattern defines a represention for its grammar along with an
interpreter that uses the representation to interpret sentences in the language. 
The Interpreter pattern has behavioral purpose and applies to the classes.

### When to use

* when the grammar is simple (in case of complex grammars, there are better alternatives)
* efficiency is not a critical concern

## Iterator

Iterator pattern has behavioral purpose and applies to objects. The pattern provides 
a way to access the elements of an aggregate object sequentially without exposing 
its underlying representation. 

### When to use

* to access an aggregate object's contents without exposing its internal representation
* to support multiple traversals of aggregate objects
* to provide a uniform interface for traversing different aggregate structures 
(to support polymorphic iteration) 

## Mediator

Mediator pattern has behavioral purpose and applies on objects.
The pattern defines an object that encapsulates how a set of objects interact.
It promotes loose coupling by keeping objects from referring to each
other explicitly, and it lets you vary their interaction independently. 

### When to use

* a set of objects communicate in well-defined but complex ways
* reusing an object is difficult because it refers to and communicates with many other objects
* a behavior that's distributed between several classes should be customizable without a lot of subclassing

## Memento

Memento without violating encapsulation, captures and externalizes an object's internal
state so that the object can be restored to this state later. The pattern has behavioral
purpose and applies to the objects.

### When to use

* a snapshot of an object's state must be saved so that it can be restored to that state later
* a direct interface to obtaining the state would expose implementation details and break the object's encapsulation 

## Observer

Observer defines a one-to-many dependency between objects so that when one object 
changes state, all its dependents are notified and updated automatically. The pattern
has behavioral purpose and applies to the objects.

### When to use

* when an abstraction has two aspects, one dependent on the other
* when a change to one object requires changing others, and you don't know how many objects need to be changed
* when an object should be able to notify other objects without making assumptions about who these objects are

## State

The pattern allows an object to alter its behavior when its internal state changes.
The object will appear to change its class. It has behavioral purpose and applies 
to the objects.

### When to use

* when an object's behavior depends on its state, and it must change its behavior at run-time depending on that state
* operations have large, multipart conditional statements that depend on the object's state

## Strategy

Strategy defines a family of algorithms, encapsulates each one, and makes them 
interchangeable. It lets the algorithm vary independently fromclients that use it. 
The pattern has behavioral purpose and applies to the objects.

### When to use

* many related classes differ only in their behavior
* you need different variants of an algorithm
* an algorithm uses data that clients shouldn't know about

## Template Method

Template method defines the skeleton of an algorithm in an operation, deferring some
steps to subclasses. It lets subclasses redefine certain steps of an algorithm 
without changing the algorithm's structure. The pattern has behavioral purpose and
applies to the classes.

### When to use

* to implement the invariant parts of an algorithm once and leave it up to subclasses to implement the behavior that can vary
* when common behavior among subclasses should be factored and localizedin a common class to avoid code duplication
* to control subclasses extensions

## Visitor

Visitor represents an operation to be performed on the elements of an object
structure. It lets you define a new operation without changing the classes of 
the elements on which it operates. The pattern has behavioral purpose and applies 
to the objects.

### When to use

* an object structure contains many classes of objects with differing interfaces, 
and you want to perform operations on these objects that depend on their concrete classes
* many distinct and unrelated operations need to be performed on objects in an object structure, 
and you want to avoid "polluting" their classes with these operations
* the classes defining the object structure rarely change, but you often want
to define new operations over the structure
