#include <vector>
struct Document;

struct IPrinter{
  virtual void print(Document& doc) = 0;
};
 
struct IScanner {
  virtual void scan(Document& doc) = 0;
};
 
struct IFax {
  virtual void fax(Document& doc) = 0;
};


struct Printer : IPrinter {
  void print(Document& doc) override;
};

struct Scanner : IScanner {
  void scan(Document& doc) override;
};

struct Fax : IFax {
  void fax(Document& doc) override;
};

// Interface to select only necessary interfaces
struct IMachine: IPrinter, IScanner {};

struct Machine : IMachine {
  IPrinter& printer;
  IScanner& scanner;

  Machine(IPrinter& printer, IScanner& scanner)
    : printer{printer},
      scanner{scanner}
  {
  }

  void print(Document& doc) override {
    printer.print(doc);
  }
  void scan(Document& doc) override;
};


int main() {
  return 0;
}
