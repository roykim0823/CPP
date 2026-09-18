#pragma once
#include <memory>
#include <string>

// pimpl ("pointer to implementation").
// This header is the entire compile-time surface of the class: clients see the
// public API and one opaque pointer. Change the implementation - add members,
// change containers, pull in <vector> or a third-party header - and nothing
// that includes this file has to be recompiled, and (with care) the ABI holds.
class Person
{
public:
  explicit Person(std::string name);
  ~Person();                                  // out-of-line: Impl is incomplete here

  Person(Person&&) noexcept;                  // movable...
  Person& operator=(Person&&) noexcept;
  Person(const Person&) = delete;             // ...but not copyable unless we write it
  Person& operator=(const Person&) = delete;

  const std::string& name() const;
  void greet() const;
  void remember(const std::string& fact);
  size_t memories() const;

private:
  class Impl;                                 // declared, never defined here
  std::unique_ptr<Impl> impl_;
};
