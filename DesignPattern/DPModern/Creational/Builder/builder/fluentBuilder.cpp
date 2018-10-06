#include <iostream>
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

// fluent builder
struct HtmlBuilder
{
  HtmlBuilder(string root_name)
  {
    root.name = root_name;
  }
  
  // return a HtmlBuilder reference
  HtmlBuilder& add_child(string child_name, string child_text)
  {
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
    return *this;
  }

  // pointer based
  HtmlBuilder* add_child_2(string child_name, string child_text)
  {
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
    return this;
  }

  string str() { return root.str(); }

  operator HtmlElement() const { return root; }
  HtmlElement root;
};

int main()
{
  // Use Fluent Builder
  cout << "1th example: fluent Builder, by refenence" << endl;
  HtmlBuilder builder{ "ul" };
  // Use chained call by returning reference
  builder.add_child("li", "hello").add_child("li", "world");
  cout << builder.str() << endl;
  cout << endl;

  // Use Fluent Builder
  cout << "2nd example: fluent Builder, by pointer" << endl;
  HtmlBuilder builder2{ "ul" };
  // Use chained call by returning pointer
  builder2.add_child_2("li", "hello")->add_child_2("li", "world");
  cout << builder2.str() << endl;
  cout << endl;
  
  return 0;
}
