// Copyright (c) 2019 Edwin
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start, m_end;

public:
    Timer() {
        m_start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        m_end = std::chrono::high_resolution_clock::now();
        stop();
    }

    void stop() {
        long long int start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start).time_since_epoch().count();
        long long int end = std::chrono::time_point_cast<std::chrono::microseconds>(m_end).time_since_epoch().count();
        long long int duration = end - start;
        double ms = duration * 0.001;

        std::cout << duration << " microseconds (" << ms << " milliseconds)" << std::endl;
    }
};

#endif
