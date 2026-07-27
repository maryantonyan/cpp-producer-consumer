#include "Producer.h"
#include "Logger.h"

#include <random>
#include <thread>
#include <chrono>
#include <atomic>

thread_local std::mt19937 rng(std::random_device{}());
thread_local std::uniform_int_distribution<int> processingTimeDist(100, 1000);

static std::atomic<int> nextTaskId{ 1 };

void producer(ThreadSafeQueue& queue, Statistics& statistics, int id) {
    for (int i{ 1 }; i <= 10; ++i) {
        const Task task{ nextTaskId++, processingTimeDist(rng)};
        log("[Producer ", id, "] Produced task ", task.id, " (", task.processingTimeMs, " ms)");

        queue.push(task);
        ++statistics.producerTasksCreated[id - 1];
        std::this_thread::sleep_for(std::chrono::milliseconds(task.processingTimeMs));
    }
}
