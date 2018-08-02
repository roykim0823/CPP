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

  // build is the fuction to construct
  static unique_ptr<HtmlBuilder> build(string root_name)
  {
    return make_unique<HtmlBuilder>(root_name);
  }

private:
  friend class HtmlBuilder;
  
  // Make constructors private (hide constructors)
  // so, builder is the only way to construct HtmlElement
  HtmlElement() {}
  HtmlElement(const string& name, const string& text)
    : name(name),
      text(text)
  {
  }

};

struct HtmlBuilder
{
  HtmlBuilder(string root_name)
  {
    root.name = root_name;
  }


  HtmlBuilder& add_child(string child_name, string child_text)
  {
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
    return *this;
  }

  HtmlElement root;

  string str() { return root.str(); }

  operator HtmlElement() const { return root; }

};

int main()
{
  string words[] = { "hello", "world" };
  
  HtmlElement e = HtmlElement::build("ul")
    ->add_child("li", "hello").add_child("li", "world");	// it returns by operator()
  cout << e.str() << endl;

  getchar();
  return 0;
}
