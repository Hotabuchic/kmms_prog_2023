#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "bubble_sort.hpp"
/*
TEST(ArraysEqual, AnyElementsCount) {
int size = 6;
int actual[] = {1, 8, 2, 5, 3, 11};
BubbleSort::sort(actual, size);
int expected[] = {1, 4, 3, 5, 8, 11};

ASSERT_EQ(size, std::size(expected))
<< "Разные размеры ожидаемого и отсортированного массивов";

for (int i = 0; i < size; i++) {
ASSERT_EQ(expected[i], actual[i])
<< "Массив ожидаемый и отсортировнный отличаются в элементе с индексом "
<< i;
}
}
*/
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}