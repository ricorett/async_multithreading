#include "header.h"
std::mutex print_mutex;

void calculate(int thread_num, int total_length) {
    auto start_time = std::chrono::high_resolution_clock::now();
    
    // Выводим идентификатор потока
    std::thread::id this_id = std::this_thread::get_id();
    
    // Прогресс-бар
    std::string progress_bar(total_length, ' ');
    
    for (int i = 0; i < total_length; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Эмуляция длительной операции
        
        // Обновляем прогресс-бар
        progress_bar[i] = '#';
        
        // Выводим состояние прогресса
        {
            std::lock_guard<std::mutex> lock(print_mutex);
            std::cout << "\rThread " << thread_num << " [" << this_id << "] [" << progress_bar << "]" << std::flush;
        }
    }
    
    // Вычисление времени выполнения
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    
    // Выводим время выполнения
    {
        std::lock_guard<std::mutex> lock(print_mutex);
        std::cout << "\rThread " << thread_num << " [" << this_id << "] finished in " 
                  << std::fixed << std::setprecision(2) << duration.count() << " seconds.\n";
    }
}

int main() {
    int num_threads, total_length;
    
    std::cout << "Enter number of threads: ";
    std::cin >> num_threads;
    
    std::cout << "Enter length of calculation (progress bar length): ";
    std::cin >> total_length;
    
    std::vector<std::thread> threads;
    
    // Запускаем потоки
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(calculate, i + 1, total_length);
    }
    
    // Ждём завершения всех потоков
    for (auto &t : threads) {
        t.join();
    }
    
    std::cout << "All threads have finished their work.\n";
    
    return 0;
}
