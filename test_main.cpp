#include <gtest/gtest.h>
#include "workWithArrays.hpp"

// для теста отсортированного массива
TEST(sortedTest, mergeSortTest){
    float* array = new float[3]{1, 2, 3}; // массив уже отсортирован
    float* array1 = new float[5]{2, 1, 3, 4, 5}; // массив не отсортирован в начале
    float* array2 = new float[5]{1, 2, 3, 5, 4}; // массив не остортирован в конце
    float* array3 = new float[5]{1, 2, 4, 3, 5}; // массив не отсортирован в середине
        // добавить на нарушения порядка в различных местах

    // проверяем, что функция возвращает true
    EXPECT_TRUE(isSorted(array, 3));
    EXPECT_FALSE(isSorted(array1, 5)); // проверка на нарушение в начале
    EXPECT_FALSE(isSorted(array2, 5)); // проверка на нарушение в конце
    EXPECT_FALSE(isSorted(array3, 5)); // проверка на нарушение в середине
    
    delete[] array; // не забываем освобождать память
    delete[] array1;
    delete[] array2;
    delete[] array3;
}

// тест для функции поиска
TEST(searchTest, linearSerchTest){
    float* array = new float[3]{1, 2, 3};
    float* array1 = new float[6]{1, 2, 3, 4, 4, 5};
    // добавить на проверки число в разных частях массива и при дубликатах

    // проверим что функция возвращает индекс корректно
    EXPECT_EQ(linearSearch(array, 3, 3), 2); // проверка на середину списка
    EXPECT_EQ(linearSearch(array, 3, 5), -1); // проверка на несуществующий элемент
    EXPECT_EQ(linearSearch(array1, 6, 1), 0); // проверка на начало списка
    EXPECT_EQ(linearSearch(array1, 6, 5), 5); // проверка на конец списка
    EXPECT_EQ(linearSearch(array1, 6, 4), 3); // проверка на дубликаты

    delete[] array;
    delete[] array1;
}