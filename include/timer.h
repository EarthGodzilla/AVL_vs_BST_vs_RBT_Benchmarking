#pragma once
#include <chrono>
using namespace std;

class Timer {
public:
    Timer() : start(chrono::high_resolution_clock::now()) {}

    double elapsedMs() const {
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration<double, milli>(end - start).count();
    }

private:
    chrono::high_resolution_clock::time_point start;
};