#include <iostream>

template <typename T>
class Amount
{
public:
	double getValue() const
	{
		return static_cast<T const&>(*this).getValue();
	}
};

/* Say we have two implementations for this interface: one that always returns a constant, 
   and one whose value can be set. 
   These two implementations inherit from the CRTP Amount base class:
*/

class Constant42 : public Amount<Constant42>
{
public:
	double getValue() const {return 42;}
};
 
class Variable : public Amount<Variable>
{
public:
	explicit Variable(int value) : value_(value) {}
   	double getValue() const {return value_;}
private:
	int value_;
};

/* Finally, let’s build a client for the interface, 
   that takes an amount and that prints it to the console:
*/
template<typename T>
void print(Amount<T> const& amount)
{
	std::cout << amount.getValue() << '\n';
}

/* The most important thing to note is that, although the Amount class is used polymorphically, 
   there isn’t any virtual in the code. This means that the polymorphic call has been resolved 
   at compile-time, thus avoiding the run-time cost of virtual functions.
*/
