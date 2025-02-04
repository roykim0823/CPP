//********************************************************
// The following code example is taken from the book
//  C++ Move Semantics - The Complete Guide
//  by Nicolai M. Josuttis (www.josuttis.com)
//  http://www.cppmove.com
//
// The code is licensed under a
//  Creative Commons Attribution 4.0 International License
//  http://creativecommons.org/licenses/by/4.0/
//********************************************************


#include <array>
#include <thread>

class Tasks {
 private:
  std::array<std::thread,10> threads;  // array of threads for up to 10 tasks
  int numThreads{0};                   // current number of threads/tasks
 public:
  Tasks() = default;

  // pass a new thread:
  template <typename T>
  void start(T op) {
    threads[numThreads] = std::thread{std::move(op)};
    ++numThreads;
  }
  //...

  Tasks(Tasks&& task) {
    threads = std::move(task.threads);
    numThreads = task.numThreads;
    task.numThreads = 0;  // reset the task's numthread to avoid double join in the destructor.
  }

  Tasks& operator=(Tasks&& task) {
    // wait for join (or detach?) to assign new threads.
    for (int i = 0; i < numThreads; ++i) {
      threads[i].join();
    }
    threads = std::move(task.threads);
    numThreads = task.numThreads;
    task.numThreads = 0;
    return *this;
  }

  // at the end wait for all started threads:
  ~Tasks() {
    for (int i = 0; i < numThreads; ++i) {
      threads[i].join();
    }
  }
};
