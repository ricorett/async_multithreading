#pragma once

#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <chrono>
#include <iomanip>
#include <mutex>


void calculate(int thread_num, int total_length);