#include <iostream>
#include <cstdio>
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

int main()
{
  // <p>hello</p>
  cout << "1st Example done MANUALLY" << endl;
  auto text = "hello";
  string output;
  output += "<p>";
  output += text;
  output += "</p>";
  printf("<p>%s</p>\n", text);
  cout << endl;

  string words[] = { "hello", "world" };
  
  // <ul><li>hello</li><li>world</li></ul>
  cout << "2nd Example done with for-loop" << endl;
  ostringstream oss;
  oss << "<ul>\n";
  for (auto w : words)
    oss << "  <li>" << w << "</li>\n";
  oss << "</ul>\n";
  printf(oss.str().c_str());
  cout << endl;

  // Use HtmlElement
  cout << "3rd Example done with HtmlElement" << endl;
  HtmlElement ul{"ul", ""};
  for (auto &w : words)
	  ul.elements.push_back(HtmlElement{"li", w});
  cout << ul.str() << endl;

  getchar();
  return 0;
}
