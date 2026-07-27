#include "ThreadSafeQueue.h"

void ThreadSafeQueue::push(const Task& task) {
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if (m_closed) {
			throw std::runtime_error("Cannot push to a closed queue.");
		}

		m_queue.push(task);
	} // unlock here
	m_cv.notify_one();
}

std::optional<Task> ThreadSafeQueue::pop() {
	std::unique_lock<std::mutex> lock(m_mutex);
	m_cv.wait(lock, [this]() { return m_closed || !m_queue.empty(); });

	if (m_queue.empty()) {
		return std::nullopt;
	}

	Task task = std::move(m_queue.front());
	m_queue.pop();
	return task;
}

void ThreadSafeQueue::close() {
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if (m_closed) {
			return;
		}
		m_closed = true;
	}
	m_cv.notify_all();
}
