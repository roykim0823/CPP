#include <string>
#include <map>
#include <algorithm>

int main()
{
  std::map<std::string,double> coll;
  //...
  // find the first nonempty string in coll:
  auto pos = std::find_if (coll.begin(), coll.end(),
                           //[] (std::string const& s) {  // errror
                           [] (const std::map<std::string,double>::value_type & s) { 	// fix #1
                           //[] (const std::pair<std::string,double>& s) {  // fix #2
                           //[] (std::pair<std::string,double>& s) {        // fix #3
                           //  return s != "";
						   		return s.first != "";
                           });
}
