#pragma once

#include <iostream>
#include <mutex>

inline std::mutex coutMutex;

template<typename... Args>
void log(Args&&... args) {
    std::lock_guard lock(coutMutex);
    (std::cout << ... << args);
    std::cout << '\n';
}
