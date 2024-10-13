#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

// A. High-level modules should not depend on low-level modules.
//    Both should depend on abstractions.
// B. Abstractions should not depend on details. 
//    Details should depend on abstractions.

enum class Relationship
{
  parent,
  child,
  sibling
};

struct Person
{
  string name;
};

struct Relationships
{
  vector<tuple<Person, Relationship, Person>> relations;

  void add_parent_and_child(const Person& parent, const Person& child)
  {
    relations.push_back({parent, Relationship::parent, child});
    relations.push_back({child, Relationship::child, parent});
  }
};

struct Research // high-level
{
 Research(const Relationships& relationships)  // high-level depends on the low-level (Relationships)
 {
   auto& relations = relationships.relations;
   for (auto&& [first, rel, second] : relations)
   {
     if (first.name == "John" && rel == Relationship::parent)
     {
       cout << "John has a child called " << second.name << endl;
     }
   }
 }
};

int main()
{
  Person parent{"John"};
  Person child1{"Chris"};
  Person child2{"Matt"};

  Relationships relationships;
  relationships.add_parent_and_child(parent, child1);
  relationships.add_parent_and_child(parent, child2);

  Research _(relationships);

  return 0;
}
