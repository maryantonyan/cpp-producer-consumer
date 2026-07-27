#pragma once

#include "ThreadSafeQueue.h"
#include "Statistics.h"

void consumer(ThreadSafeQueue& queue, Statistics& statistics, int id);
