#pragma once

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <random>
#include <iomanip>
#include <windows.h>

struct COORD{
    int X;
    int Y;
};

void setCursorPosition(int x, int y);
void calculate(int thread_num, int total_length);