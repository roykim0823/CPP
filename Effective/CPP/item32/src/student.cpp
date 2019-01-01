class Person {};

class Student : public Person {};

void eat(const Person& p) {}        	// anyone can dance

void study(const Student& s) {}       // only students study


int main()
{
  Person p;  	// p is a Person
  Student s;    // s is a Student
  
  eat(p);       // fine, p is a Person
  
  eat(s);       // fine, s is a Student, and a Student is-a Person
  
  study(s);     
  
  //study(p);   // error! p isn't a Student
}
