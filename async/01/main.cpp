#include "header.h"

int findMinIndex(const std::vector<int>& vec, int start) {
    int min_index = start;
    for (int i = start + 1; i < vec.size(); ++i) {
        if (vec[i] < vec[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

void selectionSort(std::vector<int>& vec) {
    for (int i = 0; i < vec.size() - 1; ++i) {
        std::promise<int> promise;
        std::future<int> future = promise.get_future();

        std::thread([&promise, &vec, i]() {
            int min_index = findMinIndex(vec, i);
            promise.set_value(min_index);
        }).detach();

        int min_index = future.get();

        if (i != min_index) {
            std::swap(vec[i], vec[min_index]);
        }
    }
}

int main() {
    std::vector<int> vec = {64, 25, 12, 22, 11};

    std::cout << "Original array: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    selectionSort(vec);

    std::cout << "Sorted array: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
