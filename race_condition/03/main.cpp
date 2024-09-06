#include "header.h"

void swap_lock(Data &data1, Data &data2) {
  std::lock(data1.mtx, data2.mtx);

  std::lock_guard<std::mutex> lock1(data1.mtx, std::adopt_lock);
  std::lock_guard<std::mutex> lock2(data2.mtx, std::adopt_lock);

  std::swap(data1.value, data2.value);

  std::cout << "swap_lock: Data1 = " << data1.value
            << ", Data2 = " << data2.value << std::endl;
}

void swap_scoped_lock(Data &data1, Data &data2) {
  std::scoped_lock lock(data1.mtx, data2.mtx);
  std::swap(data1.value, data2.value);
  std::cout << "swap_scoped_lock: Data1 = " << data1.value
            << ", Data2 = " << data2.value << std::endl;
}

void swap_unique_lock(Data &data1, Data &data2) {
  std::unique_lock<std::mutex> lock1(data1.mtx, std::defer_lock);
  std::unique_lock<std::mutex> lock2(data2.mtx, std::defer_lock);

  std::lock(lock1, lock2);

  std::swap(data1.value, data2.value);

  std::cout << "swap_unique_lock: Data1 = " << data1.value
            << ", Data2 = " << data2.value << std::endl;
}

int main() {
  Data data1(10);
  Data data2(20);

  swap_lock(data1, data2);
  swap_scoped_lock(data1, data2);
  swap_unique_lock(data1, data2);

  return 0;
}