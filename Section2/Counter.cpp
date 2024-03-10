#include <iostream>
#include <thread>
#include <mutex>

class Counter {
    public:
        Counter() : count(0) {};

	void increase_count_by_1() {
	    std::lock_guard<std::mutex> countLock(countMutex);
            count++;
	}

	void show() {
	    std::cout << "count = " << count << std::endl;
	}

    private:
        unsigned int count;
	std::mutex countMutex;
};

void counter_fn(Counter& counter, size_t loop) {
    for (size_t i = 0; i < loop; ++i) {
        counter.increase_count_by_1();
    }
}

int main() {
    Counter cnt;

    // Create 10 threads each executing counter_fn(cnt, 1000000)

    // Store all threads in an array
    std::thread threadList[10];

    // Start threads
    // Using a reference wrapper to make Counter object accessible to thread lib
    for (int i = 0; i < 10; ++i) {
        threadList[i] = std::thread(counter_fn, std::ref(cnt), 1000000);
    }

    // Wait for threads to complete
    for (int i = 0; i < 10; ++i) {
        threadList[i].join();
    }

    cnt.show();
    return 0;
}
