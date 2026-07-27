#pragma once

#include "Task.h"

#include <queue>
#include <mutex>
#include <optional>
#include <condition_variable>

class ThreadSafeQueue {
	bool m_closed{ false };
	std::queue<Task> m_queue;
	mutable std::mutex m_mutex;
	std::condition_variable m_cv;

public:
	void push(const Task& task);
	std::optional<Task> pop();
	void close();
};
