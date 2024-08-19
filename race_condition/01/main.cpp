#include "header.h"

#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

std::atomic<int> client_counter(0);
std::atomic<bool> all_clients_arrived(false);

void client_thread(int max_clients) {
    while (client_counter.load(std::memory_order_relaxed) < max_clients) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        int expected = client_counter.load(std::memory_order_relaxed);
        if (expected < max_clients) {
            client_counter.fetch_add(1, std::memory_order_relaxed);
            std::cout << "Client arrived. Total clients: " << client_counter.load(std::memory_order_relaxed) << std::endl;
        }
    }

    all_clients_arrived.store(true, std::memory_order_release);
}

void operator_thread() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));

        if (client_counter.load(std::memory_order_relaxed) > 0) {
            client_counter.fetch_sub(1, std::memory_order_relaxed);
            std::cout << "Client served. Clients remaining: " << client_counter.load(std::memory_order_relaxed) << std::endl;
        }


        if (all_clients_arrived.load(std::memory_order_acquire) && client_counter.load(std::memory_order_relaxed) == 0) {
            std::cout << "No more clients to serve. Operator finished." << std::endl;
            break;
        }
    }
}

int main() {
    int max_clients;
    std::cout << "Enter maximum number of clients: ";
    std::cin >> max_clients;

    std::thread client(client_thread, max_clients);
    std::thread oper(operator_thread);

    client.join();
    oper.join();

    std::cout << "Work is done. All clients have been served." << std::endl;

    return 0;
}
