#pragma once
#include <iosfwd>
#include <memory>
#include <string>
#include <vector>
#include "Buffer.h"
#include "Viewport.h"

// THE FACADE.
// Buffer + Viewport are a small but real subsystem: allocate memory, decide
// which window looks at which region, keep cursors, flatten to the screen.
// 95% of users want none of that - they want "give me a console, print this".
class Console
{
public:
  // ---- the simple API: one call to get a working object -------------------
  static Console create_default(int width = 30, int height = 5);

  // ...and a slightly less simple one, still nowhere near the raw subsystem.
  static Console create_split(int width = 60, int height = 5);

  void write(const std::string& text);              // writes to the focused viewport
  void write(size_t viewport_index, const std::string& text);
  void focus(size_t viewport_index);
  void clear();
  void render(std::ostream& out) const;             // draw everything, with a frame

  // ---- escalation: the internals stay reachable on purpose ----------------
  // A facade simplifies; it should not imprison. Power users can still reach
  // the components and do things the simple API never anticipated.
  Buffer& buffer(size_t i = 0) { return *buffers_.at(i); }
  Viewport& viewport(size_t i = 0) { return viewports_.at(i); }
  size_t viewport_count() const { return viewports_.size(); }

  size_t add_buffer(int width, int height);         // returns the new buffer's index
  size_t add_viewport(size_t buffer_index, int width, int height,
                      int offset_x = 0, int offset_y = 0);

private:
  Console() = default;                              // built through the factory methods

  std::vector<std::shared_ptr<Buffer>> buffers_;
  std::vector<Viewport> viewports_;
  size_t focused_{0};
};
