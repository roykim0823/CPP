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

  string str() { return root.str(); }

  operator HtmlElement() const { return root; }
  HtmlElement root;
};

int main()
{
  // <p>hello</p>
  cout << "1st example: manually done" << endl;
  auto text = "hello";
  string output;
  output += "<p>";
  output += text;
  output += "</p>";
  printf("<p>%s</p>", text);
  cout << endl;

  // <ul><li>hello</li><li>world</li></ul>
  cout << "2nd example: done with for-loop" << endl;
  string words[] = { "hello", "world" };
  ostringstream oss;
  oss << "<ul>";
  for (auto w : words)
    oss << "  <li>" << w << "</li>";
  oss << "</ul>";
  printf("%s", oss.str().c_str());
  cout << endl;

  // Use HtmlElement
  cout << "3rd example: down with HtmlElement" << endl;
  HtmlElement ul{"ul", ""};
  for (auto w : words)
	  ul.elements.push_back(HtmlElement{ "li", w });
  cout << ul.str() << endl;

  // Use Simple Builder
  cout << "4th example: Simple Builder" << endl;
  HtmlBuilder builder{ "ul" };
  builder.add_child("li", "hello");
  builder.add_child("li", "world");
  cout << builder.str() << endl;
  cout << endl;
  
  return 0;
}
