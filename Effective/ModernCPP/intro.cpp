/* move semantics
   rvalues: temporary objects returned from functions
   lvalues: objects you can refer to, either by name or by following a pointer  or lvalue reference
   "if you can't take its address" -> it's usually rvalue

   Given a type T, you can have lvalues of type T as well as rvalues of type T.
   Dealing with a parameter of rvalue reference type, the parameter itself is "lvalue"
*/

class Widget {
public:
	Widget(Widget&& rhs); 	// rhs is an lvalue, though it has an rvalue reference type
	// ...
}

/* there's no terminology in C++ that distinguishes between an object that's
   a copy-constructed copy and one that's a move constructed copy
*/

void someFunc(Widget w);	// soneFunc's parameter w is passed by value

Widget w;

someFunc(wid);				// in this call to someFunc, w is a copy of wid 
							// that's created via copy construction

someFunc(std::move(wid)); 	// in this call to someFunc, w is a copy of wid 
							// that's created via move construction

