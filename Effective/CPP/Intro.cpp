/* A declaration: 
	it tells compilers about the name and type of something, but it omits certain details.
*/
extern int x;						// object declaration
std::size_t numDigits(int number); 	// function declaration
class Widget;						// class declaration
template<typename T>				// template declaration
class GraphNode;

/* Signate: 
	each function's declaration reveals its signaure. i.e., its paramter and return types.
	A function signature is the same as its type.
	The official C++ definition of "signature" excludes the function's return type.
*/

/* A definition:
	it provides compilers with the details a declaration omits.
*/
int x;								// object definition
std::size_t numDigits(int number)	// function definition
{
	std::size_t digitsSoFar = 1;
	while( (number/=10) != 0 ) ++ digitSoFar;
	return digitSoFar;
}

class Widget {						// class definition
public:
	Widget();
	~Widget();
	// ...
};

template<typename T>				// template definition
class GraphNode {
public:
	GraphNode();
	~GraphNode();
	// ...
};

/* explicit constructor
	usually preferable to non-explicit ones since it prevents compilers from performing
	unexpected (often unintended) "implicit" type conversions
*/
