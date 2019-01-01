### Mixin classes are the complimentary of CRTP
## Plugging a generic functionality over your type
The main usage of the CRTP is to add a generic functionality to a particular class. Mixin classes do that too.

Mixin classes are template classes that define a generic behaviour, and are designed to inherit from the type you wish to plug their functionality onto.

## So, CRTP or mixin class?
CRTP and mixin classes provide two approaches to the same problem: adding a generic functionality to an existing class, but with different trade-offs.

Here are the points where they differ:

### The CRTP
* impacts the definition of the existing class, because it has to inherit from the CRTP,
* client code uses the original class directly and benefits from its augmented functionalities.

### The mixin class
* leaves the original class unchanged,
* client code doesn’t use the original class directly, it needs to wrap it into the mixin to use the augmented functionality,
* inherits from a the original class even if it doesn’t have a virtual destructor. This is ok unless the mixin class is deleted polymorphically through a pointer to the original class.

Understanding these trade-off lets you choose the solution that fits best to a given situation.
