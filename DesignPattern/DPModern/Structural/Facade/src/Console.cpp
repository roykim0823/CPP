#include "Console.h"
#include <ostream>

Console Console::create_default(int width, int height)
{
  Console c;
  const size_t b = c.add_buffer(width, height);
  c.add_viewport(b, width, height);
  return c;
}

Console Console::create_split(int width, int height)
{
  Console c;
  const size_t b = c.add_buffer(width, height);
  const int left = width / 2;
  c.add_viewport(b, left, height, 0, 0);                   // viewport 0: left half
  c.add_viewport(b, width - left - 1, height, left + 1, 0); // viewport 1: right half
  for (int y = 0; y < height; ++y)                          // a divider column
    c.buffer(b).at(left, y) = '|';
  return c;
}

size_t Console::add_buffer(int width, int height)
{
  buffers_.push_back(std::make_shared<Buffer>(width, height));
  return buffers_.size() - 1;
}

size_t Console::add_viewport(size_t buffer_index, int width, int height,
                             int offset_x, int offset_y)
{
  viewports_.emplace_back(buffers_.at(buffer_index), width, height, offset_x, offset_y);
  return viewports_.size() - 1;
}

void Console::focus(size_t viewport_index)
{
  if (viewport_index >= viewports_.size())
    throw std::out_of_range("no such viewport");
  focused_ = viewport_index;
}

void Console::write(const std::string& text) { viewports_.at(focused_).write(text); }

void Console::write(size_t viewport_index, const std::string& text)
{
  viewports_.at(viewport_index).write(text);
}

void Console::clear()
{
  for (auto& v : viewports_) v.clear();
}

void Console::render(std::ostream& out) const
{
  for (const auto& buffer : buffers_)
  {
    out << '+' << std::string(buffer->width(), '-') << "+\n";
    for (int y = 0; y < buffer->height(); ++y)
    {
      out << '|';
      for (int x = 0; x < buffer->width(); ++x) out << buffer->at(x, y);
      out << "|\n";
    }
    out << '+' << std::string(buffer->width(), '-') << "+\n";
  }
}
