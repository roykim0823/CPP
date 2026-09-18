#pragma once
#include <memory>
#include <string>
#include "Buffer.h"

// Subsystem component #2.
// A window onto a rectangular region of a Buffer, with its own write cursor.
// Text that reaches the right edge wraps; text that reaches the bottom scrolls.
class Viewport
{
public:
  Viewport(std::shared_ptr<Buffer> buffer, int width, int height,
           int offset_x = 0, int offset_y = 0)
    : buffer_{std::move(buffer)}, width_{width}, height_{height},
      offset_x_{offset_x}, offset_y_{offset_y}
  {
    if (!buffer_) throw std::invalid_argument("Viewport needs a buffer");
    if (offset_x + width > buffer_->width() || offset_y + height > buffer_->height())
      throw std::invalid_argument("Viewport does not fit in its buffer");
  }

  int width() const { return width_; }
  int height() const { return height_; }

  // What the screen should show at a local coordinate.
  char char_at(int x, int y) const { return buffer_->at(offset_x_ + x, offset_y_ + y); }

  void write(const std::string& text)
  {
    for (char c : text)
    {
      if (c == '\n') { new_line(); continue; }
      if (cursor_x_ == width_) new_line();
      buffer_->at(offset_x_ + cursor_x_, offset_y_ + cursor_y_) = c;
      ++cursor_x_;
    }
  }

  void clear()
  {
    for (int y = 0; y < height_; ++y)
      for (int x = 0; x < width_; ++x)
        buffer_->at(offset_x_ + x, offset_y_ + y) = ' ';
    cursor_x_ = cursor_y_ = 0;
  }

private:
  void new_line()
  {
    cursor_x_ = 0;
    if (++cursor_y_ == height_) scroll();
  }

  void scroll()
  {
    for (int y = 1; y < height_; ++y)
      for (int x = 0; x < width_; ++x)
        buffer_->at(offset_x_ + x, offset_y_ + y - 1) = buffer_->at(offset_x_ + x, offset_y_ + y);
    cursor_y_ = height_ - 1;
    for (int x = 0; x < width_; ++x)
      buffer_->at(offset_x_ + x, offset_y_ + cursor_y_) = ' ';
  }

  std::shared_ptr<Buffer> buffer_;
  int width_, height_;
  int offset_x_, offset_y_;
  int cursor_x_{0}, cursor_y_{0};
};
