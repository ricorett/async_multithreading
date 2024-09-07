#pragma once

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <random>
#include <iomanip>


void setCursorPosition(int row, int col);
void calculate(int thread_num, int total_length, int y_position);