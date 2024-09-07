#include "header.h"
std::mutex print_mutex;

void setCursorPosition(int row, int col) {
    std::cout << "\033[" << row << ";" << col << "H" << std::flush;
}

void calculate(int thread_num, int total_length, int y_position) {
    auto start_time = std::chrono::high_resolution_clock::now();

    std::thread::id this_id = std::this_thread::get_id();
    std::string progress_bar(total_length, ' ');

    std::random_device random;
    std::mt19937 generate(random());
    std::uniform_int_distribution<> delay(50, 200);

    for (int i = 0; i < total_length; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay(generate)));

        progress_bar[i] = '#';
        {
            std::lock_guard<std::mutex> lock(print_mutex);
            setCursorPosition(y_position, 0);
            std::cout << "Thread " << thread_num << " [" << this_id << "] ["
                      << progress_bar << "]" << std::flush;
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;

    {
        std::lock_guard<std::mutex> lock(print_mutex);
        setCursorPosition(y_position, 0);
        std::cout << "Thread " << thread_num << " [" << this_id
                  << "] finished in " << std::fixed << std::setprecision(2)
                  << duration.count() << " seconds." << std::endl;
    }
}

int main() {
    int num_threads, total_length;

    std::cout << "Enter number of threads: ";
    std::cin >> num_threads;

    std::cout << "Enter length of calculation (progress bar length): ";
    std::cin >> total_length;

    std::vector<std::thread> threads;

    std::cout << "\033[2J\033[?25l" << std::flush;

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(calculate, i + 1, total_length, i + 1);
    }

    for (auto &t : threads) {
        t.join();
    }

    std::cout << "\033[?25h" << std::flush;
    std::cout << "All threads have finished their work.\n";

    return 0;
}
