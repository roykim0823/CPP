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

  // Factory Method
  static unique_ptr<HtmlBuilder> build(string root_name)
  {
    return make_unique<HtmlBuilder>(root_name);
  }

protected:	
  friend class HtmlBuilder;	// to access constructors in HtmlBuilder
 
  // hide all constructors (or private) 
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
  
  // return a HtmlBuilder reference
  HtmlBuilder& add_child(string child_name, string child_text)
  {
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
    return *this;
  }

  string str() { return root.str(); }

  // final version
  operator HtmlElement() const { 
	  return root;	// again, std::move possible here 
  }
  HtmlElement root;
};

int main()
{
  // Use factory Method
  auto builder = HtmlElement::build("ul"); 	// return unique_ptr
  (*builder).add_child("li", "hello").add_child("li", "world");
  cout << builder->str();

  // Use operator()
  HtmlElement e = HtmlElement::build("ul")
    ->add_child("li", "hello")	// since e is a pointer
	.add_child("li", "world");
  cout << e.str() << endl;

  return 0;
}
