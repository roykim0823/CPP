#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <sstream>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

using namespace std;

struct Address
{
  string street;
  string city;
  int suite;

  // Copy constructor
  Address(const string& street, const string& city, const int suite)
    : street{street},
      city{city},
      suite{suite}
  {
  }

  Address(const Address& other)
    : street{other.street},
      city{other.city},
      suite{other.suite}
  {
  }

  friend ostream& operator<<(ostream& os, const Address& obj)
  {
    return os
      << "street: " << obj.street
      << " city: " << obj.city
      << " suite: " << obj.suite;
  }
};

struct Contact
{
  string name;
  Address* address;	// a pointer is more practical instead of Address address
  
  // Copy constructor, but not generic since the Address can be changed the member
  Contact(const Contact& other)
    : name{other.name}
    //, address{ new Address{*other.address} }
  {
    address = new Address(
      other.address->street, 
      other.address->city, 
      other.address->suite
    );
  }

  // More generic copy constructor
  /*
  Contact(const Contact& other)
    : name{other.name}
    address{ new Address{*other.address} }
  {}
  */

  // Copy assignment
  Contact& operator=(const Contact& other)
  {
    if (this == &other)
      return *this;
    name = other.name;
    address = other.address;
    return *this;
  }

  Contact() : name(nullptr), address(nullptr)
  {} // required for serialization

  Contact(string name, Address* address)
    : name{name}, address{address}
  {
    //this->address = new Address{ *address };
  }


private:
  friend class boost::serialization::access;

  template <class archive>
  void save(archive& ar, const unsigned version) const
  {
    ar << name;
    ar << address;
  }

  template <class archive>
  void load(archive& ar, const unsigned version)
  {
    ar >> name;
    ar >> address;
  }

  BOOST_SERIALIZATION_SPLIT_MEMBER()

public:
  ~Contact()
  {
    delete address;
  }


  friend ostream& operator<<(ostream& os, const Contact& obj)
  {
    return os
      << "name: " << obj.name
      << " works at " << *obj.address; // note the star here
  }
};

struct EmployeeFactory
{
  static Contact main;
  static Contact aux;

  static unique_ptr<Contact> NewMainOfficeEmployee(string name, int suite)
  {
    //static Contact p{ "", new Address{ "123 East Dr", "London", 0 } };
    return NewEmployee(name, suite, main);
  }

  static unique_ptr<Contact> NewAuxOfficeEmployee(string name, int suite)
  {
    return NewEmployee(name, suite, aux);
  }

private:
  static unique_ptr<Contact> NewEmployee(string name, int suite, Contact& proto)
  {
    auto result = make_unique<Contact>(proto);
    result->name = name;
    result->address->suite = suite;
    return result;
  }
};

//Contact EmployeeFactory::main{ "", new Address{ "123 East Dr", "London", 0 } };
//Contact EmployeeFactory::aux{ "", new Address{ "123B East Dr", "London", 0 } };

int main()
{
  // this is tedious
  Contact john{ "John Doe", new Address{"123 East Dr", "London", 10} };
  Contact jane{ "Jane Doe", new Address{"123 East Dr", "London", 11} };
  cout << john << endl;
  cout << jane << endl;

  // Use "Copy and Move Operators"
  Contact worker{"", new Address{"123 East Dr", "London", 0 }};
  Contact john2{worker};	// or: Contact john = worker
  Contact jane2 = worker;	
  john2.name = "John2";
  john2.address->suite = 100;
  jane2.name = "Jane2";
  jane2.address->suite = 101;
  cout << john2 << endl;
  cout << jane2 << endl;

  auto addr = new Address{ "123, East Dr", "London", 0 };

  Contact john3{ "John3 Doe", addr };
  john3.address->suite = 123;
  Contact jane3{ "Jane3 Doe", addr };
  jane3.address->suite = 124;
  cout << john3 << endl;
  cout << jane3 << endl;

  Contact jane4{ jane3 }; // shallow copy
  jane4.address->suite = 555;
  cout << "Jane4 -> " << jane4 << endl;

  // much better. let's list employees
  Contact employee{ "Unknown", new Address{"628 Happy St", "Joy", 0} };

  // we can use this prototype to create john and jane
  Contact john5{ employee };
  john5.name = "John Doe";
  john5.address->suite = 123;

  Contact jane5{ employee };
  jane5.name = "Jane Doe";
  jane5.address->suite = 125;

  cout << john5 << "\n" << jane5 << "\n";

  delete addr;
  
  return 0;
}
