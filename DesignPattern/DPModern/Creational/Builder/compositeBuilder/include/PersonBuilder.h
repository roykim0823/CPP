#pragma once
#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase
{
protected:
  // the physical storage of Person is not present in this class
  Person& person;

  // reference assining constructor is protected: only the inheritors can use it
  explicit PersonBuilderBase(Person& person)
    : person{ person }
  {
  }
public:
  operator Person() const
  {
    return std::move(person);
  }

  // builder facets

  PersonAddressBuilder lives() const;
  PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase
{
  Person p;
public:
  PersonBuilder(): PersonBuilderBase{p}
  {
  }

};
