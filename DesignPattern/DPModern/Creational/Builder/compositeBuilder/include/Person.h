#pragma once
#include <string>
#include <iostream>

using namespace std;

class PersonBuilder;

class Person {
  // address
  std::string street_address, post_code, city;

  // employment
  std::string company_name, position;
  int annual_income = 0;

  Person() {	// Hide constructor (private)
    std::cout << "Person created\n";
  }
  
public:
  ~Person() {
    std::cout << "Person destroyed\n";
  }
  
  Person(Person&& other)
    : street_address{move(other.street_address)},
      post_code{move(other.post_code)},
      city{move(other.city)},
      company_name{move(other.company_name)},
      position{move(other.position)},
      annual_income{other.annual_income}
  {}

  Person& operator=(Person&& other) {
    if (this == &other)
      return *this;
    street_address = move(other.street_address);
    post_code = move(other.post_code);
    city = move(other.city);
    company_name = move(other.company_name);
    position = move(other.position);
    annual_income = other.annual_income;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const Person& obj) {
    return os
      << "street_address: " << obj.street_address
      << " post_code: " << obj.post_code
      << " city: " << obj.city
      << " company_name: " << obj.company_name
      << " position: " << obj.position
      << " annual_income: " << obj.annual_income;
  }

  static PersonBuilder create();

  friend class PersonBuilder;
  friend class PersonAddressBuilder;
  friend class PersonJobBuilder;
};
