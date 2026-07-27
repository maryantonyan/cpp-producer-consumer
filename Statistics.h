#pragma once

#include <atomic>
#include <vector>

struct Statistics {
    std::atomic<int> totalTasksProcessed{ 0 };

    std::vector<std::atomic<int>> producerTasksCreated;
    std::vector<std::atomic<int>> consumerTasksProcessed;

    Statistics(size_t producerCount, size_t consumerCount)
        : producerTasksCreated(producerCount),
        consumerTasksProcessed(consumerCount)
    {}
};