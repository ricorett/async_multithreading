#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <functional>
#include <numeric>

void sum_vectors(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& result, int start, int end);
double parallel_sum(int num_threads, const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& result);