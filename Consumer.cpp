#include "Consumer.h"
#include "Logger.h"

#include <thread>
#include <chrono>

void consumer(ThreadSafeQueue& queue, Statistics& statistics, int id) {
    while (true) {
        auto task = queue.pop();
        if (!task) {
            log("[Consumer ", id, "] Exiting.");
            break;
        }

        ++statistics.totalTasksProcessed;
        ++statistics.consumerTasksProcessed[id - 1];

        log("[Consumer ", id, "] Processing task ", task->id, " (", task->processingTimeMs, "ms)");
        std::this_thread::sleep_for(std::chrono::milliseconds(task->processingTimeMs));
        log("[Consumer ", id, "] Finished task ", task->id);
    }
}