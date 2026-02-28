#pragma once

#include <iostream>


/** @brief выделять память под массив и инициализировать его
    @param n размер массива
    @return инициализированный массив
    */
float* createArray(size_t n);


/** @brief заполнить массив указанным диапазоном значений  
 * @param n размер массива
 * @param min нижняя граница массива
 * @param max верхняя граница массива
 * @return массив в заполненном диапазоне
*/
float* fillArrayD(size_t n, int min, int max);


/** @brief функция заполнения отсортированными значениями
 * @param n размер массива
 * @return заполненный массив, который монотонно возрастает
 */
float* fillSorted(size_t n);


/** @brief функция сортировки массива 
 * @param arr сортируемый массив
 * @param buff буффер для временного хранения
 * @param size размер массива
 * @exception выбрасывает исключении типа invalid_argument в случае пустого массива или буффера
 */
void mergeSort(float *arr, float *buff, size_t size);


/** @brief вывод функции на экран
 * @param array массив, который нужно вывести
 * @param size размер массива
 */
template <typename E>
void printArr(E* array, size_t size){
    cout << "Ваш массив: " << endl;
    for(size_t i = 0; i < size; i++){
    cout << array[i] << " "; 
    }
    cout << endl;
    }


/** @brief функция записи массива в файл
 * @param fileName имя файла
 * @param array массив, который будет записываться
 * @param size размер массива
 */
void arrInFile(std::string& const fileName, float* array, size_t size);


/** @brief функция проверки на сортированный массив
 * @param array массив, в котором проходит проверка
 * @param size размер массива
 * @return true или false
 * @exception выбрасывает исключение вида invalid_argument, если массив пустой
 */
bool isSorted(float* array, size_t size);


/** @brief функция последовательного поиска элемента в массиве
 * @param array массив, в котором происходит поиск
 * @param size размер массива
 * @param target искомая цель
 * @return индекс возвращаемого элемента
 */
template <typename E>
size_t linearSearch(E* array, size_t size, E target){
    for(size_t i = 0; i < size; i++){
        if(array[i] == target){
            return array[i];
        }
    } return -1; // функция возвращает максимальное число, потому что переменная типа size_t может хранить только положительные значения и происходит переполнение
}