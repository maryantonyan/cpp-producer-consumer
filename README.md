# Producer–Consumer with Thread-Safe Queue

A modern C++17 implementation of the classic **Producer–Consumer** synchronization problem.

This project demonstrates how multiple producer and consumer threads communicate through a thread-safe queue implemented using modern C++ concurrency primitives. It focuses on thread synchronization, safe shared-state management, and clean concurrent program design.

---

## Features

- Multiple producer threads
- Multiple consumer threads
- Thread-safe queue
- Graceful shutdown
- Thread-safe logging
- Lock-free statistics using `std::atomic`
- RAII-based synchronization
- Modern C++17 implementation

---

## Concepts Demonstrated

- `std::thread`
- `std::mutex`
- `std::lock_guard`
- `std::unique_lock`
- `std::condition_variable`
- `std::atomic`
- `thread_local`
- RAII
- Producer–Consumer design pattern

---

## Architecture

```text
                    +-----------------------+
                    |   Producer Threads    |
                    +-----------+-----------+
                                |
                                | push()
                                v
                 +-------------------------------+
                 |        ThreadSafeQueue        |
                 |-------------------------------|
                 | std::queue<Task>              |
                 | std::mutex                    |
                 | std::condition_variable       |
                 +---------------+---------------+
                                 |
                                 | pop()
                                 v
                    +------------+------------+
                    |   Consumer Threads      |
                    +------------+------------+
                                 |
               +-----------------+-----------------+
               |                                   |
               v                                   v
     +----------------------+          +----------------------+
     |      Statistics      |          |        Logger        |
     |----------------------|          |----------------------|
     | std::atomic counters |          | std::mutex           |
     +----------------------+          +----------------------+
```

---

## Project Structure

```text
.
├── Task.h
├── ThreadSafeQueue.h
├── ThreadSafeQueue.cpp
├── Producer.h
├── Producer.cpp
├── Consumer.h
├── Consumer.cpp
├── Logger.h
├── Statistics.h
├── main.cpp
└── Makefile
```

---

## Example Output

```text
[Producer 1] Produced task 1 (639 ms)
[Producer 2] Produced task 2 (128 ms)

[Consumer 3] Processing task 1 (639 ms)
[Consumer 2] Processing task 2 (128 ms)

...

=================================
Execution Statistics
=================================

Producer 1: 10 tasks created
Producer 2: 10 tasks created
Producer 3: 10 tasks created

Consumer 1: 9 tasks processed
Consumer 2: 8 tasks processed
Consumer 3: 6 tasks processed
Consumer 4: 7 tasks processed

Total tasks processed: 30
```

---

## Build

### Windows

Open the Visual Studio solution and build the project.

### Linux / macOS

```bash
make
./ProducerConsumer
```

---

## Requirements

- C++17 or later
- Visual Studio 2022, GCC, or Clang

---

## Purpose

This project was built to deepen my understanding of modern C++ concurrency by implementing a complete Producer–Consumer system from scratch using standard library synchronization primitives.

It demonstrates practical usage of thread synchronization, mutexes, condition variables, atomics, RAII, and concurrent software design.
