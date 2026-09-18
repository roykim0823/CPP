#include "Person.h"
#include <iostream>
#include <vector>

// Everything below is invisible to every translation unit but this one.
class Person::Impl
{
public:
  explicit Impl(std::string name) : name_{std::move(name)} {}

  const std::string& name() const { return name_; }

  void greet() const
  {
    std::cout << "Hello, my name is " << name_;
    if (!facts_.empty()) std::cout << " and I remember " << facts_.size() << " thing(s)";
    std::cout << ".\n";
  }

  void remember(const std::string& fact) { facts_.push_back(fact); }
  size_t memories() const { return facts_.size(); }

private:
  std::string name_;
  std::vector<std::string> facts_;   // adding this member recompiles only Person.cpp
};

Person::Person(std::string name) : impl_{std::make_unique<Impl>(std::move(name))} {}

// The destructor must be defined where Impl is complete, otherwise unique_ptr's
// deleter cannot be instantiated. This is the one piece of pimpl boilerplate
// everybody trips over.
Person::~Person() = default;
Person::Person(Person&&) noexcept = default;
Person& Person::operator=(Person&&) noexcept = default;

const std::string& Person::name() const { return impl_->name(); }
void Person::greet() const { impl_->greet(); }
void Person::remember(const std::string& fact) { impl_->remember(fact); }
size_t Person::memories() const { return impl_->memories(); }
