# Facade

> Expose several components through a single, simple interface.

## Motivation

- Balancing complexity and presentation/usability.
- Many subsystems are built for *flexibility*: lots of small classes, each doing one
  thing, wired together by the caller. API consumers mostly want it to **just work**.
- A typical app has a handful of "expert" callers and a great many casual ones.
  Optimising the API for the experts punishes everyone else.

Think of a house: behind the wall there is plumbing, wiring, gas, insulation.
You interact with a light switch and a tap. The wall is the facade — and you can
still open it up when you actually need to rewire something.

## Intent

Provide a simple, easy to understand/use interface over a large and sophisticated
body of code. The facade **adds no new functionality** — it only reorganises access
to functionality that already exists in the subsystem.

## Structure

```
            ┌──────────────────────────────┐
  client ──►│           Facade             │   simple, task-oriented API
            │  create_default(), write()   │
            └───────┬──────────┬───────────┘
                    │          │
            ┌───────▼───┐  ┌───▼───────┐  ┌───────────┐
            │  Buffer   │  │ Viewport  │  │    ...    │   the subsystem:
            └───────────┘  └───────────┘  └───────────┘   fine-grained, flexible,
                    ▲                                     and still reachable
                    └─────── escalation ──────── client
```

Two properties are worth calling out because people often get them wrong:

1. **The facade is not a wall.** The subsystem classes stay public. A client that
   outgrows the simple API escalates to the components instead of forking your code.
2. **The facade owns no logic.** If you find yourself implementing behaviour in it,
   you are probably writing a Mediator or a service layer, not a Facade.

## The example in this folder

A console/terminal, the classic version of this pattern:

| File | Role |
| --- | --- |
| `include/Buffer.h` | Subsystem: a flat `width × height` grid of characters. Knows nothing about screens. |
| `include/Viewport.h` | Subsystem: a window onto a region of a `Buffer`, plus a cursor, wrapping and scrolling. |
| `include/Console.h`, `src/Console.cpp` | **The facade.** Presets, `write()`, `render()` — and accessors that hand the components back. |
| `src/facade.cpp` | Three levels of use: simple, preset, escalated. |
| `include/Person.h`, `src/Person.cpp` | pimpl, for the comparison below. |
| `src/pimpl.cpp` | Runs the pimpl example and prints the contrast. |

Getting a working console is one line:

```cpp
Console console = Console::create_default(30, 5);
console.write("Facade keeps the easy things easy.\n");
console.render(cout);
```

Doing that without the facade means: allocate a `Buffer` of the right size, decide
where the `Viewport` sits inside it, keep the two in sync, track the cursor,
handle wrapping, then walk the grid to draw it. All of that is still available —
`console.viewport(i)`, `console.buffer(i)`, `console.add_viewport(...)` — which is
what `power_usage()` in `src/facade.cpp` does to place an inset window that no
preset offers.

### Build & run

```sh
cmake -S . -B build
cmake --build build
./build/facade
./build/pimpl
```

## Notes on writing a good facade

- **Design it from the caller's task, not from the subsystem.** `create_default()`,
  not `configure(buffer, viewport, policy)`. If the facade's parameters mirror the
  subsystem's constructors, it isn't buying anything.
- **Offer presets, not one god-function with 12 defaulted arguments.**
- **Keep it thin.** Delegation plus a little assembly. No state machine of its own.
- **One facade per use case is fine.** A read-only facade and an authoring facade
  over the same subsystem is a perfectly good design.
- **Don't make the subsystem `private`/`friend`-only** just to force people through
  the front door. You will be wrong about someone's requirements.
- The subsystem must remain usable *without* the facade — that is the test of
  whether you have a facade or an abstraction leak.

## Facade vs. its neighbours

| Pattern | Interfaces | Purpose |
| --- | --- | --- |
| **Facade** | many → one | *Convenience.* A simpler entry point to a subsystem you also ship raw. |
| **Adapter** | one → one | *Compatibility.* Make an existing interface match the one a client expects. |
| **Proxy** | one → same | *Control.* Same interface, plus lazy loading / access checks / remoting. |
| **Mediator** | many ↔ many | *Decoupling.* Colleagues talk to the mediator instead of each other; it owns logic. |
| **Bridge** | abstraction ↔ implementation | *Variation.* Let interface and implementation change independently. |

## Is pimpl a sort of facade?

**Short answer: no — pimpl is a degenerate Bridge, not a Facade.** It *feels* like
one because both put a narrow interface in front of something messier, but they are
solving different problems:

| | Facade | pimpl |
| --- | --- | --- |
| Hides | a *set* of collaborating classes | a *single* class's own internals |
| Motive | usability of the API | compile-time and ABI decoupling |
| Relationship | 1 facade → N subsystem classes | 1 handle → 1 implementation |
| Subsystem visible? | yes, on purpose (escalation) | no, that's the entire point |
| Interface | *different* from (simpler than) the subsystem's | *identical* to what the class would expose anyway |
| Cost | a thin layer of delegation | heap allocation, an indirection, no inlining across the boundary |
| GoF classification | Facade | Bridge ("handle/body", "compilation firewall") |

The last row is the crisp version: pimpl is Bridge with exactly one implementation,
where the flexibility you bought is spent on *build times and binary stability*
rather than on swapping implementations at runtime. `Person` in `src/Person.cpp`
grows a `std::vector<std::string>` member and pulls in `<vector>`; nothing that
includes `Person.h` recompiles, and `sizeof(Person)` stays at one pointer.

Where the confusion is legitimate: a facade whose implementation is itself hidden
behind a pimpl is common and sensible (a library's public header exposes
`Console` with one opaque pointer, and `Console.cpp` drives `Buffer`/`Viewport`).
That object is doing both jobs at once — simplifying the API *and* firewalling
compilation — but they remain two separate decisions, and you can take either
without the other.

### Reading the pimpl code

`include/Person.h` is the whole compile-time surface. Clients see the public
functions plus one opaque member:

```cpp
class Person
{
public:
  explicit Person(std::string name);
  ~Person();                                  // out-of-line: Impl is incomplete here
  Person(Person&&) noexcept;                  // movable...
  Person& operator=(Person&&) noexcept;
  Person(const Person&) = delete;             // ...but not copyable unless we write it
  Person& operator=(const Person&) = delete;
  // ...
private:
  class Impl;                                 // declared, never defined here
  std::unique_ptr<Impl> impl_;
};
```

`class Impl;` is a *nested forward declaration*. The type exists as a name; its
layout is unknown to anyone including this header, which is exactly what makes it
a firewall. Note what the header does **not** include: no `<vector>`, no `<iostream>`,
no third-party headers — only `<memory>` and `<string>`, which the signatures need.

`src/Person.cpp` defines `Person::Impl` and forwards each public function to it:

```cpp
class Person::Impl
{
  // ...
  std::string name_;
  std::vector<std::string> facts_;   // adding this member recompiles only Person.cpp
};

Person::Person(std::string name) : impl_{std::make_unique<Impl>(std::move(name))} {}
void Person::greet() const { impl_->greet(); }
```

The forwarding functions are the price of admission: every public method costs one
extra one-line definition. That tedium is the main practical argument *against*
pimpl for classes that aren't part of a published interface.

#### The four things that trip people up

**1. The destructor must be out of line.**

```cpp
Person::~Person() = default;        // in the .cpp, where Impl is complete
```

`~unique_ptr<Impl>` must call `delete impl_`, and deleting an incomplete type is
undefined behaviour — the standard library `static_assert`s on it. If you omit the
destructor from the header (implicit) or write `~Person() = default;` *in* the
header, the compiler instantiates the deleter where `Impl` is still incomplete and
you get a wall of errors from inside `<memory>`. Declare it in the header, define
it in the .cpp. This is the one piece of pimpl boilerplate everyone hits once.

**2. Declaring the destructor kills the move operations.**

A user-declared destructor suppresses the implicit move constructor and move
assignment. Without the two `Person(Person&&)` declarations, `std::move(p)` would
silently fall back to *copy* — which here fails to compile, since `unique_ptr`
isn't copyable. So they are declared in the header and `= default`ed in the .cpp,
for the same completeness reason as the destructor.

**3. Moving is cheap; copying is a decision.**

```cpp
Person moved = std::move(p);      // src/pimpl.cpp — the handle moves, the Impl never does
```

The move copies an 8-byte pointer and nulls the source. The `Impl` — the string and
the vector of facts — stays at the same heap address; nothing is reallocated, and
anything holding a reference into the implementation stays valid. `moved.greet()`
still reports two remembered facts. `p` is left valid-but-empty, so calling
`p.greet()` afterwards would dereference a null pointer.

Copying, on the other hand, can't be defaulted: `unique_ptr` is move-only, so a
copy needs a hand-written `Person(const Person& other) : impl_{std::make_unique<Impl>(*other.impl_)} {}`
in the .cpp. Here it is `= delete`d, which is the honest default until someone
needs value semantics.

**4. `sizeof` tells you what the client is coupled to.**

`src/pimpl.cpp` prints both:

```
sizeof(Person)  = 8 bytes (just the pointer)
sizeof(Console) = 56 bytes (a facade is a normal object; it hides nothing from the compiler)
```

`Person` is one pointer no matter how `Impl` grows — that's the ABI stability.
`Console`, a facade, is a completely ordinary object whose layout is public; the
facade simplifies *calling* the subsystem, not *compiling against* it.

#### What it buys, and what it costs

| Buys | Costs |
| --- | --- |
| Changing private members/headers recompiles one .cpp, not the world | One heap allocation per object |
| Stable ABI: layout change without breaking callers | An indirection on every call |
| Implementation headers stay out of the public header | No inlining across the boundary |
| Genuinely private internals (not just `private:`) | Forwarding boilerplate per method |

Use it in library headers that many translation units include, or where binary
compatibility matters. Don't use it for small value types, anything on a hot path,
or classes internal to one target — there the indirection is pure loss.

## Summary

- Build a Facade to provide a simplified API over a set of classes.
- May wish to (optionally) expose internals through the facade.
- May allow users to 'escalate' to use more complex APIs if they need to.
- The facade adds convenience, not behaviour — keep it thin and delegation-only.
- pimpl looks similar but answers a different question (compile/ABI, not usability);
  reach for it in library headers, not as a way to "simplify" an API.
