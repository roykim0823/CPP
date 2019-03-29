#include "user.h"

// initialize the static member
key User::seed = 0;
bimap<key, string> User::names{};

void naive_flyweight()
{
  User john_doe{ "John", "Doe" };
  User jane_doe{ "Jane", "Doe" };

  cout << "John " << john_doe << endl;
  cout << "Jane " << jane_doe << endl;

  User::info();
}

struct User2	// use boost::flyweight
{
  flyweight<string> first_name, last_name;

  User2(const string &first_name, const string &last_name)
    : first_name(first_name),
      last_name(last_name) {}
};

void boost_flyweight()
{
  User2 user1{"John", "Smith"};
  User2 user2{"Jane", "Smith"};

  cout << user1.first_name << endl;

  cout << boolalpha
       << (&user1.first_name.get() == &user2.first_name.get()) << endl;
  cout << boolalpha
       << (&user1.last_name.get() == &user2.last_name.get()) << endl;
}

int main()
{
  naive_flyweight();
  boost_flyweight();

  getchar();
  return 0;
}
