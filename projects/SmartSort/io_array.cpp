#include "io_array.hpp"

void IOArray::print_array(int *arr, const int &n) {
    std::cout << "Result is:";
    for (int i = 0; i < n; i++) {
        std::cout << " " << arr[i];
    }
}