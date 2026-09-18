#include <iostream>
#include "Console.h"

using namespace std;

// 1. The easy path: the facade hands back a working object and takes text.
//    The caller never hears the words "buffer" or "viewport".
void simple_usage()
{
  cout << "--- simple: one call, it just works ---\n";
  Console console = Console::create_default(30, 5);
  console.write("Facade keeps the easy things easy.\n");
  console.write("Line two.");
  console.render(cout);
}

// 2. A second canned configuration. Still the facade, still no subsystem types.
void slightly_richer_usage()
{
  cout << "\n--- still simple: a preset with two viewports ---\n";
  Console console = Console::create_split(60, 5);
  console.write(0, "left pane text that is long enough to wrap around");
  console.write(1, "right pane");
  console.render(cout);
}

// 3. Escalation: the components are still there for whoever needs them.
//    This is the "optionally expose internals" part of the pattern.
void power_usage()
{
  cout << "\n--- escalated: reach past the facade into the subsystem ---\n";
  Console console = Console::create_default(40, 6);

  // Add a viewport the presets never offered: a 10x2 window in the middle.
  const size_t inset = console.add_viewport(0, 10, 2, 15, 2);
  console.write("background text ");
  console.write("that flows on and on and on and on and on");

  Viewport& v = console.viewport(inset);   // subsystem object, handed out on request
  v.clear();
  v.write("INSET!");

  console.buffer(0).at(0, 5) = '*';        // raw grid access, no ceremony
  console.render(cout);
}

int main()
{
  simple_usage();
  slightly_richer_usage();
  power_usage();
  return 0;
}
