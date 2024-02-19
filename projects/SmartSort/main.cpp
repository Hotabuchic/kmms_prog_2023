#include "bubble_sort.hpp"
#include "io_array.hpp"

int main() {
    int arr[] = {8, 2, 5};
    const int arr_size = std::size(arr);

    BubbleSort::sort(arr, arr_size);
    IOArray::print_array(arr, arr_size);
}
