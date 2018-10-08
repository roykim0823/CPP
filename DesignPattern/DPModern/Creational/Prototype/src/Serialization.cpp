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

  Address() : street(nullptr), city(nullptr) {}
  // Copy constructor
  Address(const Address& other) :
  	street{other.street}, city{other.city}, suite{other.suite}
  {}

  Address(const string& stree, const string& city, const int suite) :
  	street{street}, city{city}, suite{suite}
  {}

  friend ostream& operator<<(ostream& os, const Address& obj)
  {
    return os
      << "street: " << obj.street
      << " city: " << obj.city
      << " suite: " << obj.suite;
  }

private:
  friend class boost::serialization::access;

  template<class Ar> void serialize(Ar& ar, const unsigned int version)
  {
    ar & street;
    ar & city;
    ar & suite;
  } 
}; 

struct Contact
{
  string name;
  Address* address = nullptr;

  // required for serialization
  //Contact() : name(nullptr), address(nullptr) {}

  friend ostream& operator<<(ostream& os, const Contact& obj)
  {
    return os
      << "name: " << obj.name
      << " address: " << *obj.address;
  }
private:
  friend class boost::serialization::access;

  template<class Ar> void serialize(Ar& ar, const unsigned int version)
  {
    ar & name;
    ar & address; // no * since boost is smart enough to figure out it
  }

};

int main()
{
  Contact john;
  john.name = "John Doe";
  john.address = new Address{ "123 East Dr", "London", 123 };
  cout << john << endl;
/*	// compilation error
  auto clone = [](const Contact& c)
  {
	// 1. Serialize the contact
    ostringstream oss;
    boost::archive::text_oarchive oa(oss);
    oa << c;
    string s = oss.str();

	// 2. Deserialize the contact
    istringstream iss(oss.str());
    boost::archive::text_iarchive ia(iss);
    Contact result;
    ia >> result;
    return result;
  };
*/
//  Contact jane = clone(john);
//  jane.name = "Jane Doe";
//  jane.address->street = "123B West Dr";
//  jane.address->suite = 300;

//  cout << jane << endl;

  return 0;
}
