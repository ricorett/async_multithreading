#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <future>
#include <iterator>
#include <thread>

const std::size_t MIN_BLOCK_SIZE = 1000;

template<typename Iterator, typename Func>
void parallel_for_each(Iterator begin, Iterator end, Func func) {
    auto length = std::distance(begin, end);

    if (length <= MIN_BLOCK_SIZE) {
        std::for_each(begin, end, func);
        return;
    }

    Iterator mid = begin;
    std::advance(mid, length / 2);

    auto future = std::async(std::launch::async, parallel_for_each<Iterator, Func>, begin, mid, func);
    parallel_for_each(mid, end, func);
    future.get();
}
