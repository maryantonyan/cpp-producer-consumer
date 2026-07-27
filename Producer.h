#pragma once

#include "ThreadSafeQueue.h"
#include "Statistics.h"

void producer(ThreadSafeQueue& queue, Statistics& statistics, int id);
