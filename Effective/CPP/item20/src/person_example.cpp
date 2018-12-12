#include <iostream>
#include <string>
using namespace std;

class Person {
public:
  Person() { cout << "Person()" << endl; }
  virtual ~Person() { cout << "~Person()" << endl; }
 
private:
  string name, address;
};


class Student: public Person {
public:
  Student() { cout << "Student()" << endl; }
  virtual ~Student() { cout << "~Student()" << endl; }
 
private:
  string schoolName, schoolAddress;
};


// Expensive version with pass by value.
//Student returnStudent(Student s) { return s; }

// Cheap version with pass by reference-to-const
const Student& returnStudent(const Student& s) { return s; }

int main()
{
  cout << "Student plato" << endl;

  Student plato;                      // Plato studied under Socrates

  cout << "calling returnStuent(plato)" << endl;
   
  returnStudent(plato);               // call returnStudent

  cout << "After calling..." << endl;
}
