#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;

struct HtmlBuilder;

struct HtmlElement
{
  string name;
  string text;
  vector<HtmlElement> elements;
  const size_t indent_size = 2;

  HtmlElement() {}
  HtmlElement(const string& name, const string& text)
    : name(name),
      text(text)
  {
  }

  string str(int indent = 0) const
  {
    ostringstream oss;
    string i(indent_size*indent, ' ');
    oss << i << "<" << name << ">" << endl;
    if (text.size() > 0)
      oss << string(indent_size*(indent + 1), ' ') << text << endl;

    for (const auto& e : elements)
      oss << e.str(indent + 1);

    oss << i << "</" << name << ">" << endl;
    return oss.str();
  }
};

// Builder Pattern: outsource the piecewise construction of an object into a separate class
struct HtmlBuilder
{
  HtmlBuilder(string root_name)
  {
    root.name = root_name;
  }

  // Naive Version: void to start with
  void add_child(string child_name, string child_text)
  {
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
  }

  string str() { return root.str(); }
  
  HtmlElement root;

};

int main()
{
  string words[] = { "hello", "world" };
  
  // Easier with Simple HtmlBuilder
  cout << "Simple HtmlBuilder" << endl;
  HtmlBuilder builder{"ul"};
  builder.add_child("li", "hello");	// void add
  builder.add_child("li", "world");
  cout << builder.str() << endl;

  getchar();
  return 0;
}
