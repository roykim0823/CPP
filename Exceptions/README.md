# Exception Handling in C++
* try: represents a block of code that can throw an exception
* catch: represents a block of code that executed when a particular exception is thrown.
* throw: Used to throw exception. Also used to list the exceptions that a function throws, but doesn't handle itself

## Why Exception Handling?
Following are main advantages of exception handling over traditional error handling
1. Seperation of Error handling code from Normal Code:
	In traditional error handling codes, there are always if else conditions to handle errors.
	These conditions and the code to handle errors get mixed up with the normal flow. This makes
	the code less readable and maintainable. With try catch blocks, the code for error handling
	becomes separate from the normal flow.
2. Functions/Methods can handle any exceptions they choose:
	A function can throw many exceptions, but may choose to handle some of them. The other exceptions
	which are thrown, but not caught can be handled by caller. If the caller chooses not to catch them,
	then the exceptions are handled by caller of the caller.
	In C++, a function can specify the exceptions that it throws using the throw keyword. The caller
	of this function must handle the exception in some way (either by specifying it again or catching it)
3. Grouping of Error Types:
	In C++, both basic types and objects can be thrown as exceptions. We can create a hierarchy of
	exception objects, group exceptions in namespaces or classes, categorize them according to types.
