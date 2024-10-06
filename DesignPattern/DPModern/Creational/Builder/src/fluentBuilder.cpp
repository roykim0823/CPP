#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;

struct HtmlElement
{
  string name;
  string text;
  vector<HtmlElement> elements;
  const size_t indent_size = 2;

  HtmlElement() {}
  HtmlElement(const string& name, const string& text)
    : name(name), text(text) { }

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
  
  // simple builder: return void
  void add_child(string child_name, string child_text)
  {
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
  }
  
  // fluent builder: return the Builder reference
  HtmlBuilder& add_child_ref(string child_name, string child_text)
  {
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
	return *this;
  }
  
  // fluent builder: return the pointer, reference version is better
  HtmlBuilder* add_child_ptr(string child_name, string child_text)
  {
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
	return this;
  }

  string str() { return root.str(); }

  HtmlElement root;
};

int main() {
  // Without Builder
  // <ul><li>hello</li><li>world</li></ul>
  string words[] = { "hello", "world" };
  
  cout << "Scenario: done with for-loop" << endl;
  ostringstream oss;
  oss << "<ul>";
  for (auto w : words)
    oss << "  <li>" << w << "</li>";
  oss << "</ul>";
  printf("%s", oss.str().c_str());
  cout << endl;

  // Use HtmlElement
  cout << "Scenario: down with HtmlElement" << endl;
  HtmlElement ul{"ul", ""};
  for (auto w : words)
	  ul.elements.push_back(HtmlElement{ "li", w });
  cout << ul.str() << endl;

  // Use Simple Builder
  cout << "Simple Builder" << endl;
  HtmlBuilder builder{ "ul" };
  builder.add_child("li", "hello");
  builder.add_child("li", "world");
  cout << builder.str() << endl;
  
  // Use Fluent Builder
  cout << "Fluent Builder by reference" << endl;
  HtmlBuilder builder2{ "ul" };
  builder2.add_child_ref("li", "hello").add_child_ref("li", "world");
  cout << builder2.str() << endl;
  
  // Use Fluent Builder
  cout << "Fluent Builder by pointer" << endl;
  HtmlBuilder builder3{ "ul" };
  builder3.add_child_ptr("li", "hello")->add_child_ptr("li", "world");
  cout << builder3.str() << endl;
  
  return 0;
}
