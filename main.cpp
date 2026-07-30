#include "ThreadSafeQueue.h"
#include "Producer.h"
#include "Consumer.h"

#include <iostream>
#include <cassert>
#include <thread>
#include <atomic>
#include <vector>

int main() {
	ThreadSafeQueue queue;
    constexpr int NUM_OF_PRODUCERS{ 3 };
    constexpr int NUM_OF_CONSUMERS{ 4 };
    Statistics statistics{ NUM_OF_PRODUCERS, NUM_OF_CONSUMERS };

    std::vector<std::thread> producers;
    producers.reserve(NUM_OF_PRODUCERS);
    for (int i{ 1 }; i <= NUM_OF_PRODUCERS; ++i) {
        producers.emplace_back(
            producer,
            std::ref(queue),
            std::ref(statistics),
            i
        );
    }

    std::vector<std::thread> consumers;
    consumers.reserve(NUM_OF_CONSUMERS);
    for (int i{ 1 }; i <= NUM_OF_CONSUMERS; ++i) {
        consumers.emplace_back(
            consumer,
            std::ref(queue),
            std::ref(statistics),
            i
        );
    }
    
    for (std::thread& p : producers) {
        p.join();
    }

    queue.close();

    for (std::thread& c : consumers) {
        c.join();
    }

    std::cout
        << "\n=================================\n"
        << "Execution statistics\n"
        << "=================================\n\n";

    for (size_t i{ 0 }; i < statistics.producerTasksCreated.size(); ++i) {
        std::cout << "Producer " << i + 1 << ": " << statistics.producerTasksCreated[i] << " tasks created\n";
    }

    for (size_t i{ 0 }; i < statistics.consumerTasksProcessed.size(); ++i) {
        std::cout << "Consumer " << i + 1 << ": " << statistics.consumerTasksProcessed[i] << " tasks processed\n";
    }

    std::cout << "\nTotal tasks processed: " << statistics.totalTasksProcessed << '\n';

    int totalTasksCreated{ 0 };
    for (const auto& count : statistics.producerTasksCreated) {
        totalTasksCreated += count;
    }
    assert(totalTasksCreated == statistics.totalTasksProcessed);
	return 0;
}
