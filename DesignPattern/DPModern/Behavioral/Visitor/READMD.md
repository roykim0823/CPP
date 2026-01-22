# Visitor Pattern
### A tool for structure traversal rather than anything else.
A pattern where a component (visitor) is allowed to traverse the entire inheritance hierarchy.
Implemented by propagating a single `visit()` method throughout the entire hierarchy.

## Motivation
- Need to define a new operation on an entire class hierarchy
  - E.g., make a document model printable to HTML/Markdown
- Do not want to keep modifying every class in the hierarchy
  - Keep OCP & SRP
- Need access to the non-common aspects of classes in the hierarchy
  - Cannot put everything into a single interface
- Create an external component to handle rendering
  - But preferably avoid type checks

## Example
1. Intrusive visitor: visitor_intrusive.cpp
2. Reflective Visitor: visitor_reflective.cpp
3. Classic Visitor (Double Dispatch): visitor_double.cpp
  - Double dispatch is to provide a way of handling the various types in a static type language.
4. Acyclic Vistor based on RTTI: visitor_acyclic.cpp
5. Multimethods: multimethods.cpp
  - Use CRTP
6. `std::visit`: std_visit.cpp
  - Not a visitor pattern, but `std::visit` provides a way of accessing the correct part of a variant type.

## Summary (Double Dispatch)
- Propagate an `accept(visitor *v)` method throughout the entire hierarchy
- Create a visitor with `visit(Foo*)`, `visit(Bar*)`, ... for each element in the hierarchy
- Each accept() simply calls visitor.visit(this)
