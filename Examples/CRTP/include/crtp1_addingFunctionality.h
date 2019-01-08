class Sensitivity_base
{
public:
	double getValue() const { return value; }
    void setValue(double value) { this->value = value; }
    // rest of the sensitivity's rich interface...
private:
	double value;
};

class Sensitivity_extension
{
public:
	double getValue() const { return value; }
	void setValue(double value) { this->value = value; }
			 
	void scale(double multiplicator)
	{
		setValue(getValue() * multiplicator);
    }
    
	void square()
   	{
   		setValue(getValue() * getValue());
   	}
   	
	void setToOpposite()
   	{
   		scale(-1);
   	};
private:
	double value;
};

/* So far so good. But imagine now that we have another class, that also has a value, 
   and that also needs the 3 numerical capabilities above. 
   Should we copy and paste the 3 implementations over to the new class?

   By now I can almost hear some of you scream to use template non-member functions, 
   that would accept any class and be done with it. Please bear with me just another moment, 
   we will get there I promise.

   This is where the CRTP comes into play. Here we can factor out the 3 numerical functions
   into a separate class.
*/

template <typename T>
struct NumericalFunctions
{
	void scale(double multiplicator)
	{
		T& underlying = static_cast<T&>(*this);
		underlying.setValue(underlying.getValue() * multiplicator);
	}
	
	void square()
    {
		T& underlying = static_cast<T&>(*this);
		underlying.setValue(underlying.getValue() * underlying.getValue());
	}
	
	void setToOpposite()
	{
		scale(-1);
	}
};

class Sensitivity : public NumericalFunctions<Sensitivity>
{
public:
	double getValue() const { return value; }
    void setValue(double value) { this->value = value; }
    // rest of the sensitivity's rich interface...
private:
	double value;
};

/* Why not non-member template functions?
Ah, there we are.

Why not use template non-member functions that could operate on any class, 
including Sensitivity and other candidates for numerical operations? 
They could look like the following:
*/

template <typename T>
void scale(T& object, double multiplicator)
{
	object.setValue(object.getValue() * multiplicator);
}

template <typename T>
void square(T& object)
{
	object.setValue(object.getValue() * object.getValue());
}

template <typename T>
void setToOpposite(T& object)
{
	object.scale(object, -1);
}

/* What’s all the fuss with the CRTP?
There is at least one argument for using the CRTP over non-member template functions: 
the CRTP shows in the interface.

With the CRTP, you can see that Sensitivity offers the interface of NumericalFunctions

And with the template non-member functions you don’t. 
-> They would be hidden behind a #include somewhere.

And even if you knew the existence of these 3 non-member functions, 
you wouldn’t have the guarantee that they would be compatible with a particular class 
(maybe they call get() or getData() instead of getValue()?). 
Whereas with the CRTP the code binding Sensitivity has already been compiled, 
so you know they have a compatible interface.
*/
