#include <gtest/gtest.h>
#include "workWithArrays.hpp"

// для теста отсортированного массива
TEST(sortedTest, mergeSortTest){
    float* array = new float[3]{1, 2, 3}; // массив уже отсортирован
    float* array1 = new float[3]{2, 1, 5}; // массив не отсортирован
    
    // проверяем, что функция возвращает true
    EXPECT_TRUE(isSorted(array, 3));
    EXPECT_FALSE(isSorted(array1, 3));
    
    delete[] array; // не забываем освобождать память
    delete[] array1;
}

// тест для функции поиска
TEST(searchTest, linearSerchTest){
    float* array = new float[3]{1, 2, 3};
    
    // проверим что функция возвращает индекс корректно
    EXPECT_EQ(linearSearch(array, 3, 3), 2);
    EXPECT_EQ(linearSearch(array, 3, 5), -1);
}