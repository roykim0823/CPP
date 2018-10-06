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

struct HtmlBuilder
{
  HtmlBuilder(string root_name)
  {
    root.name = root_name;
  }

  // Enhanced Version: Fluent Interface
  // returning a reference to the builder itself, the builder calls can be chained.
  HtmlBuilder& add_child(string child_name, string child_text)
  {
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
    return *this;
  }

  string str() { return root.str(); }

  HtmlElement root;

};

int main()
{
  string words[] = { "hello", "world" };

  // Fluent HtmlBuilder
  cout << "Fluent HtmlBuilder" << endl;
  HtmlBuilder fluent_builder{ "ul" };
  fluent_builder.add_child("li", "hello").add_child("li", "world");
  cout << fluent_builder.str() << endl;

  getchar();
  return 0;
}
