#pragma once
#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

#include <boost/bimap.hpp>
#include <boost/flyweight.hpp>
#include <boost/flyweight/key_value.hpp>
using namespace boost;
using namespace flyweights;

// coloring in the console by-letter vs using ranges

// naive
//typedef uint32_t key;
typedef unsigned key;

// Assume User stores millions of user names for MMORPG game
struct User
{
  User(const string& first_name, const string& last_name)
    : first_name{add(first_name)}, last_name{add(last_name)}
  {}

  const string& get_first_name() const {
    return names.left.find(last_name)->second;
  }

  const string& get_last_name() const {
    return names.left.find(last_name)->second;
  }

  static void info() {
    for (auto entry : names.left) {
      cout << "Key: " << entry.first << ", Value: " << entry.second << endl;
    }
  }

  friend ostream& operator<<(ostream& os, const User& obj) {
    return os
      << "first_name: " << obj.first_name << " " << obj.get_first_name()
      << " last_name: " << obj.last_name << " " << obj.get_last_name();
  }

  static key seed;

protected:
  key first_name, last_name;
  static bimap<key, string> names; 	// boost::bimap (a bidirectional map)

  static key add(const string& s)
  {
    auto it = names.right.find(s);
    if (it == names.right.end())
    {
	  // add it
      key id = ++seed;
      names.insert({seed, s});
      return id;
    }
    return it->second;
  }
};
