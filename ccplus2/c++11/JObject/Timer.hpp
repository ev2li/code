#pragma once

#include <chrono>
#include <iostream>

class Timer {
public:
    Timer(){
       m_StartTimePoint = std::chrono::high_resolution_clock::now(); 
    }
    
    ~Timer(){
        stop();
    }
    
    void stop(){
        auto endTimePoint = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(
            m_StartTimePoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(
            endTimePoint).time_since_epoch().count();
        auto duration = end - start;
        double ms = duration * 0.001; 
        printf("%lld us (%lf ms)\n", duration, ms);
        fflush(stdout);
    }


private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
};
