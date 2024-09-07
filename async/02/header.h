#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <future>
#include <iterator>
#include <thread>

void parallel_for_each(Iterator begin, Iterator end, Func func);