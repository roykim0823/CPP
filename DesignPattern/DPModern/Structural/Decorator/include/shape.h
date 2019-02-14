#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

struct Shape
{
  virtual std::string str() const = 0;
};

struct Circle : Shape
{
  float radius;

  Circle(){}

  explicit Circle(const float radius)
    : radius{radius}
  {}

  void resize(float factor)
  {
    radius *= factor;
  }

  std::string str() const override
  {
    std::ostringstream oss;
    oss << "A circle of radius " << radius;
    return oss.str();
  }
};

struct Square : Shape
{
  float side;

  Square(){}

  explicit Square(const float side)
    : side{side}
  {
  }

  std::string str() const override
  {
    std::ostringstream oss;
    oss << "A square with side " << side;
    return oss.str();
  }
};
