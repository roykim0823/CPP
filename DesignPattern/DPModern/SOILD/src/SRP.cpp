#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Journal
{
  string title;
  vector<string> entries;

  explicit Journal(const string& title)
    : title{title}
  {
  }

  void add(const string& entry);

};

void Journal::add(const string& entry)
{
  static int count = 1;
  entries.push_back(std::to_string(count++)
    + ": " + entry);
}

// Better to save in a seperate class
struct PersistenceManager
{
  static void save(const Journal& j, const string& filename)
  {
    ofstream ofs(filename);
    for (auto& s : j.entries)
      ofs << s << endl;
  }
};

int main()
{
  Journal journal{"Dear Diary"};
  journal.add("I ate a bug");
  journal.add("I cried today");

  PersistenceManager pm;
  pm.save(journal, "diary.txt");
}
