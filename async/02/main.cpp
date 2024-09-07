#include "header.h"

int main() {
    std::vector<int> vec(10000, 1);

    auto print_and_increment = [](int& x) {
        x += 1;
        std::cout << x << " ";
    };

    parallel_for_each(vec.begin(), vec.end(), print_and_increment);

    std::cout << "\nModified array: ";
    for (const auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
