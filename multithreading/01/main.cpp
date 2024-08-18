#include "queue.h"

std::mutex mtx;
int client_counter = 0;
bool all_clients_arrived = false;

void client_thread(int max_clients) {
    while (client_counter < max_clients) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard<std::mutex> lock(mtx);
        if (client_counter < max_clients) {
            ++client_counter;
            std::cout << "Client arrived. Total clients: " << client_counter << std::endl;
        }
    }

    std::lock_guard<std::mutex> lock(mtx);
    all_clients_arrived = true;
}

void operator_thread() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::lock_guard<std::mutex> lock(mtx);

        if (client_counter > 0) {
            --client_counter;
            std::cout << "Client served. Clients remaining: " << client_counter << std::endl;
        }

        if (all_clients_arrived && client_counter == 0) {
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
