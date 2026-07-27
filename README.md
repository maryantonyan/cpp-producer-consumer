**Producer-Consumer with Thread-Safe Queue**



This project demonstrates a classic Producer-Consumer implementation in modern C++17.

Multiple producer and consumer threads communicate through a thread-safe queue

implemented using mutexes and condition variables.



==============================================================

**Features**

✔ Multiple producers

✔ Multiple consumers

✔ Thread-safe queue

✔ Graceful shutdown

✔ Thread-safe logging

✔ Task statistics

✔ Modern C++17

✔ RAII synchronization



==============================================================

**Concepts demonstrated**

std::thread

std::mutex

std::lock\_guard

std::unique\_lock

std::condition\_variable

std::atomic

thread\_local

RAII

Producer-Consumer pattern


==============================================================

**Project structure**

```text
Task.h

ThreadSafeQueue.h/.cpp

Producer.h/.cpp

Consumer.h/.cpp

Logger.h

Statistics.h

main.cpp

Makefile
```text


==============================================================

**Example output**

```text

\[Producer 1] Produced task 1 (639 ms)

\[Producer 2] Produced task 2 (128 ms)

\[Producer 3] Produced task 3 (875 ms)

\[Consumer 3] Processing task 1 (639ms)

\[Consumer 2] Processing task 2 (128ms)

\[Consumer 1] Processing task 3 (875ms)

\[Producer 2] Produced task 4 (311 ms)

\[Consumer 2] Finished task 2

\[Consumer 4] Processing task 4 (311ms)

\[Producer 2] Produced task 5 (632 ms)

\[Consumer 2] Processing task 5 (632ms)

\[Consumer 4] Finished task 4

\[Consumer 3] Finished task 1

\[Producer 1] Produced task 6 (549 ms)

\[Consumer 4] Processing task 6 (549ms)

\[Consumer 1] Finished task 3

\[Producer 3] Produced task 7 (436 ms)

\[Consumer 3] Processing task 7 (436ms)

\[Consumer 2] Finished task 5

\[Producer 2] Produced task 8 (459 ms)

\[Consumer 1] Processing task 8 (459ms)

\[Producer 1] Produced task 9 (511 ms)

\[Consumer 4] Finished task 6

\[Consumer 2] Processing task 9 (511ms)

\[Consumer 3] Finished task 7

\[Producer 3] Produced task 10 (335 ms)

\[Consumer 4] Processing task 10 (335ms)

\[Consumer 1] Finished task 8

\[Producer 2] Produced task 11 (706 ms)

\[Consumer 3] Processing task 11 (706ms)

\[Consumer 4] Finished task 10

\[Producer 3] Produced task 12 (417 ms)

\[Consumer 1] Processing task 12 (417ms)

\[Consumer 2] Finished task 9

\[Producer 1] Produced task 13 (976 ms)

\[Consumer 4] Processing task 13 (976ms)

\[Consumer 1] Finished task 12

\[Producer 3] Produced task 14 (117 ms)

\[Consumer 2] Processing task 14 (117ms)

\[Consumer 2] Finished task 14

\[Producer 3] Produced task 15 (109 ms)

\[Consumer 1] Processing task 15 (109ms)

\[Consumer 3] Finished task 11

\[Producer 2] Produced task 16 (814 ms)

\[Consumer 2] Processing task 16 (814ms)

\[Consumer 1] Finished task 15

\[Producer 3] Produced task 17 (639 ms)

\[Consumer 3] Processing task 17 (639ms)

\[Consumer 4] Finished task 13

\[Producer 1] Produced task 18 (124 ms)

\[Consumer 1] Processing task 18 (124ms)

\[Consumer 1] Finished task 18

\[Producer 1] Produced task 19 (506 ms)

\[Consumer 4] Processing task 19 (506ms)

\[Producer 3] Produced task 20 (618 ms)

\[Consumer 1] Processing task 20 (618ms)

\[Consumer 3] Finished task 17

\[Consumer 2] Finished task 16

\[Producer 2] Produced task 21 (551 ms)

\[Consumer 3] Processing task 21 (551ms)

\[Consumer 4] Finished task 19

\[Producer 1] Produced task 22 (189 ms)

\[Consumer 2] Processing task 22 (189ms)

\[Consumer 2] Finished task 22

\[Producer 1] Produced task 23 (651 ms)

\[Consumer 4] Processing task 23 (651ms)

\[Producer 3] Produced task 24 (918 ms)

\[Consumer 1] Finished task 20

\[Consumer 2] Processing task 24 (918ms)

\[Producer 2] Produced task 25 (518 ms)

\[Consumer 3] Finished task 21

\[Consumer 1] Processing task 25 (518ms)

\[Consumer 1] Finished task 25

\[Producer 2] Produced task 26 (634 ms)

\[Consumer 3] Processing task 26 (634ms)

\[Consumer 4] Finished task 23

\[Producer 1] Produced task 27 (349 ms)

\[Consumer 1] Processing task 27 (349ms)

\[Producer 3] Produced task 28 (567 ms)

\[Consumer 2] Finished task 24

\[Consumer 4] Processing task 28 (567ms)

\[Consumer 1] Finished task 27

\[Producer 1] Produced task 29 (196 ms)

\[Consumer 2] Processing task 29 (196ms)

\[Consumer 2] Finished task 29

\[Producer 2] Produced task 30 (681 ms)

\[Consumer 3] Finished task 26

\[Consumer 1] Processing task 30 (681ms)

\[Consumer 4] Finished task 28

\[Consumer 1] Finished task 30

\[Consumer 4] Exiting.

\[Consumer 2] Exiting.

\[Consumer 3] Exiting.

\[Consumer 1] Exiting.


=================================

Execution statistics

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

==============================================================

**Build**

*Windows*
Open the Visual Studio solution and build.


*Linux/macOS*
```bash
make
./ProducerConsumer
```

==============================================================