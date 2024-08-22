#pragma once

#include <algorithm>  // для std::swap
#include <iostream>
#include <mutex>
#include <thread>


class Data {
 public:
  int value;
  std::mutex mtx;

  Data(int val) : value(val) {}
};

void swap_lock(Data &data1, Data &data2);
void swap_scoped_lock(Data &data1, Data &data2);
void swap_unique_lock(Data &data1, Data &data2);