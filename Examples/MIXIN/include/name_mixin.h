#include <iostream>
#include <string>

class Name
{
public:
	Name(std::string firstName, std::string lastName)
	: firstName_(std::move(firstName))
	, lastName_(std::move(lastName)) {}
					    
	void print() const
	{
		std::cout << lastName_ << ", " << firstName_ << '\n';
	}
				    
private:
	std::string firstName_;
	std::string lastName_;
};

/* here is a new requirement: we need to be able to print this name several times in a row.
   We could add a repeat method to the Name class. But the concept of repeatedly call the print 
   method is something that could apply to other classes, like a PhoneNumber class that could also 
   have a print() method.

   The idea of the mixin class is to isolate the generic functionality into its own class, template 
   this class on the type we want to plug in onto, and derive from that type:
*/
template<typename Printable>
struct RepeatPrint : Printable
{
	explicit RepeatPrint(Printable const& printable) : Printable(printable) {}
	void repeat(unsigned int n) const
	{
		while (n-- > 0)
		{
			// this-> in the implementation of the repeat method. Without it the code would not compile
			// since the compiler is not sure where print is declared without this
			this->print();
		}
	}   
};

// To avoid specifying template arguments explicitly we use a function that deduces them
template<typename Printable>
RepeatPrint<Printable> repeatPrint(Printable const& printable) {
	return RepeatPrint<Printable>(printable);
}
