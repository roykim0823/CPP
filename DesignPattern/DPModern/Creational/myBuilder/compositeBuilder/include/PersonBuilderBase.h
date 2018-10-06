#pragma once
#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase 	// a facet builder that uses different builders
{

protected:
  // a reference to the object that's being built. it is for the sub-builders.
  // Note that the physical storage of Person is not present in this class.
  // The root class only holds a reference, not the constructed object
  Person& person;
  
  explicit PersonBuilderBase(Person& person)	// called by PersonAddressBuilder and PersonJobBuilder
    : person{ person }                      // since it is protected
  {
  }

public:
  operator Person()
  {
    return std::move(person);
  }

  // builder facets
  PersonAddressBuilder lives() const;
  PersonJobBuilder works() const;
};
