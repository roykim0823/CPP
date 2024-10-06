#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;

struct HtmlBuilder;

class HtmlElement
{
  public:
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
 
private:
  string name;
  string text;
  vector<HtmlElement> elements;
  const size_t indent_size = 2;
  // hide all constructors (or private) 
  // so, builder is the only way to construct HtmlElement
  // -> force users to use the builder
  HtmlElement() {}
  HtmlElement(const string& name, const string& text)
    : name(name),
    text(text)
  {
  }
};

class HtmlBuilder
{
  public:
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
  private:
  HtmlElement root;
};

int main()
{
    // easier
  HtmlBuilder builder{ "ul" };
  builder.add_child("li", "hello").add_child("li", "world");
  cout << builder.str() << endl;


  auto builder2 = HtmlElement::build("ul")  // use factor method
    ->add_child("li", "hello").add_child("li", "world");
  cout << builder2.str() << endl;

  auto builder3 = HtmlElement::build("ul");  // use factor method
  (*builder3).add_child("li", "hello").add_child("li", "world");
  cout << builder2.str() << endl;
  return 0;
}
