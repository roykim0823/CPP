#include <string>
#include <map>
#include <algorithm>

int main()
{
  std::map<std::string,double> coll;                  
  //...
  // find the first nonempty string in coll:
  auto pos = std::find_if (coll.begin(), coll.end(),
                           //[] (std::string const& s) { 
                           [] (const std::map<std::string,double>::value_type & s) { 	// fixed
                           //[] (const std::pair<std::string,double>& s) { 
                           //[] (std::pair<std::string,double>& s) { 
                           //  return s != "";
						   		return s.first != "";
                           });
}
