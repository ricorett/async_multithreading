#pragma once
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

void client_thread(int max_clients);
void operator_thread();