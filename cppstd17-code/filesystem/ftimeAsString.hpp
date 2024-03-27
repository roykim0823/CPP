//********************************************************
// The following code example is taken from the book
//  C++17 - The Complete Guide
//  by Nicolai M. Josuttis (www.josuttis.com)
//  http://www.cppstd17.com
//
// The code is licensed under a
//  Creative Commons Attribution 4.0 International License
//  http://creativecommons.org/licenses/by/4.0/
//********************************************************


#include <string>
#include <chrono>
#include <filesystem>

std::string asString(const std::filesystem::file_time_type& tp)
{
  using system_clock = std::chrono::system_clock;
  auto t = system_clock::to_time_t(tp + (system_clock::now()
                                          - decltype(tp)::clock::now()));
  // convert to calendar time (including skipping trailing newline):
  std::string ts = std::ctime(&t);
  ts.resize(ts.size()-1);
  return ts;
}

