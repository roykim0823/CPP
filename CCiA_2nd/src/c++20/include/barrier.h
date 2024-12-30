#pragma once

#include <thread>
#include <atomic>
#include <condition_variable>

class barrier_spin {

	unsigned const thresh_hold;
	std::atomic<unsigned> count;
	std::atomic<unsigned> generation;

public:
	explicit barrier_spin(unsigned thresh_hold_) :
		thresh_hold(thresh_hold_), count(thresh_hold_), generation(0) {}

    void wait() {
		unsigned const my_generation = generation;

		if (!--count) {
			count = thresh_hold;
			++generation;
		} else {
			while (generation == my_generation)
				std::this_thread::yield();
		}
	}
};

class barrier_cond {
public:
    explicit barrier_cond(std::size_t iCount) :
        mThreshold(iCount),
        mCount(iCount),
        mGeneration(0) {
    }

    void Wait() {
        std::unique_lock<std::mutex> lLock{ mMutex };
        auto lGen = mGeneration;
        if (!--mCount) {
            mGeneration++;
            mCount = mThreshold;
            mCond.notify_all();
        }
        else {
            mCond.wait(lLock, [this, lGen] { return lGen != mGeneration; });
        }
    }

private:
    std::mutex mMutex;
    std::condition_variable mCond;
    std::size_t mThreshold;
    std::size_t mCount;
    std::size_t mGeneration;
};