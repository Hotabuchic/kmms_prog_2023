#include <clocale>
#include <iostream>


int main() {
    std::setlocale(LC_ALL, "Russian");

    const char space = ' ';
    const int arr_size = 5;
    const int array[] = {3, 6 , 5, 9, 10};
    int max_num = array[0];
    int min_num = array[0];

    for (int i = 1; i < arr_size; i++) {
        if (array[i] > max_num) {
            max_num = array[i];
        } else if (array[i] < min_num) {
            min_num = array[i];
        }
    }
    const double result = double(max_num) / min_num;

    std::wcout << L"Изначальный массив: " << std::endl;
    for (int x : array) {
        std::cout << x << space;
    }
    std::cout << std::endl;
    std::wcout << L"Максимальное число: " << max_num << std::endl;
    std::wcout << L"Минимальное число: " << min_num << std::endl;
    std::wcout << L"Отношение максимального числа к минимальному: " << result << std::endl;
    return 0;
}
