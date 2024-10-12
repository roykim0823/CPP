#include <vector>
struct Document;

// A problem is that some implementor of this interface
// might not need scanning or faxing 
// -> split up interfaces so that implementors can pick and choose 
//	  depending on their needs
struct IMachine
{
  virtual void print(Document& doc) = 0;
  virtual void fax(Document& doc) = 0;
  virtual void scan(Document& doc) = 0;
};

struct MFP : IMachine
{
  void print(Document& doc) override {}
  void fax(Document& doc) override {}
  void scan(Document& doc) override {}
};

int main() {
  return 0;
}