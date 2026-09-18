#pragma once
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

// Subsystem component #1.
// A flat, fixed-size grid of characters. It knows nothing about screens,
// cursors, fonts or windows - it is just memory with a 2D accessor.
class Buffer
{
public:
  Buffer(int width, int height)
    : width_{width}, height_{height},
      characters_(static_cast<size_t>(width) * static_cast<size_t>(height), ' ')
  {
    if (width <= 0 || height <= 0)
      throw std::invalid_argument("Buffer dimensions must be positive");
  }

  int width() const { return width_; }
  int height() const { return height_; }

  char& at(int x, int y) { return characters_[index(x, y)]; }
  char at(int x, int y) const { return characters_[index(x, y)]; }

  void clear() { std::fill(characters_.begin(), characters_.end(), ' '); }

private:
  size_t index(int x, int y) const
  {
    if (x < 0 || x >= width_ || y < 0 || y >= height_)
      throw std::out_of_range("Buffer coordinates out of range");
    return static_cast<size_t>(y) * static_cast<size_t>(width_) + static_cast<size_t>(x);
  }

  int width_, height_;
  std::vector<char> characters_;
};
