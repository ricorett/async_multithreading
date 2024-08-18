#include "header.h"

void sum_vectors(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& result, int start, int end) {
    for (int i = start; i < end; ++i) {
        result[i] = a[i] + b[i];
    }
}

double parallel_sum(int num_threads, const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& result) {
    std::vector<std::thread> threads;
    int size = a.size();
    int chunk_size = size / num_threads;

    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < num_threads; ++i) {
        int start = i * chunk_size;
        int end = (i == num_threads - 1) ? size : start + chunk_size;
        threads.emplace_back(sum_vectors, std::cref(a), std::cref(b), std::ref(result), start, end);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    return duration.count();
}

int main() {
    std::vector<int> sizes = {1000, 10000, 100000, 1000000};

    std::vector<int> num_threads = {2, 4, 8, 16};

    unsigned int hardware_concurrency = std::thread::hardware_concurrency();
    std::cout << "Available hardware concurrency: " << hardware_concurrency << " cores" << std::endl;

    std::cout << "Results (Time in seconds):\n";
    std::cout << "Size\tThreads\tTime\n";

    for (int size : sizes) {
        std::vector<int> a(size, 1);
        std::vector<int> b(size, 2);
        std::vector<int> result(size);

        for (int threads : num_threads) {
            double time_taken = parallel_sum(threads, a, b, result);
            std::cout << size << "\t" << threads << "\t" << time_taken << "\n";
        }
    }

    return 0;
}
