#pragma once
#include "PersonBuilderBase.h"

// It isn't meant to be inherited: it's only meant as a utility that 
// let us initiate the process of setting up a builder
class PersonBuilder: public PersonBuilderBase
{

  Person p;

public:
  PersonBuilder() : PersonBuilderBase{p} {}
};
