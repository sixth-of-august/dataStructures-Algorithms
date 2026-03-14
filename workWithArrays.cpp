#include <cstdlib>
#include <ctime>
#include <random>
#include <fstream>
#include <iostream>
#include "workWithArrays.hpp" // заголовочный файл

using namespace std; 

/** @brief выделять память под массив и инициализировать его
    * @param n размер массива
    * @return инициализированный массив
    */
float* createArray(size_t n){
    return new float[n](); //возвращаем инициализированный массив
}


/** @brief заполнить массив указанным диапазоном значений  
 * @param n размер массива
 * @param min нижняя граница массива
 * @param max верхняя граница массива
 * @return массив в заполненном диапазоне
*/
float* fillArrayD(size_t n, int min, int max){
    
    float* somePointer; // указатель на массив 
    somePointer = new float[n]; // выделение памяти

    random_device rd; 
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);

    // заполнение случайным количеством чисел из диапазона
    for(size_t i = 0; i < n; i++){
        somePointer[i] = distrib(gen);
    }// не использовать rand, так как он ограничивает диапазон случайных чисел

    return somePointer;
}


/** @brief функция заполнения отсортированными значениями
 * @param n размер массива
 * @return заполненный массив, который монотонно возрастает
 */
float* fillSorted(size_t n){
    float* somePointer; // указатель на массив 
    somePointer = new float[n]; // выделение памяти

    somePointer[0] = rand() % 100 * 0.1; // случайно заполняем первый элемент

    // заполнение случайным количеством чисел из диапазона
    for(size_t i = 1; i < n; i++){
        somePointer[i] = somePointer[i - 1] + (rand() % 10 * 0.1);
    } // монотонно увеличиваем результат
    
    return somePointer;
}


/** @brief функция сортировки массива 
 * @param arr сортируемый массив
 * @param buff буффер для временного хранения
 * @param size размер массива
 * @exception выбрасывает исключении типа invalid_argument в случае пустого массива или буффера
 */
void mergeSort(float *arr, float *buff, size_t size){
    if(arr == nullptr || buff == nullptr){
        throw invalid_argument("Массив или буфер не может быть пустым");
    }

    // если массив содержит меньше 1 элемента - сортировка не требуется
    if (size <= 1) return;
    
    // устанавливаем середину для массива
    size_t middle = size / 2;

    // рекурсивно вызываем функцию, чтобы каждый раз сортировать половинки
    mergeSort(arr, buff, middle);
    mergeSort(arr + middle, buff + middle, size - middle); // используем смещение указателями

    size_t i = 0, left = 0, right = middle; // переменные счётчики для прохода по элементам
    while(left < middle && right < size){   // выполняем сравнение двух отсортированных частей массива
        if(arr[right] < arr[left]){         // сравниваем элементы двух разных частей
            buff[i] = arr[right]; right++;  // переходим к следующему элементу в правом массиве
        } else{
            buff[i] = arr[left]; left++; // переходим к следующему элементу в левом массиве
        } i++; // увеличиваем индекс, для записии в следующий элемент массива
    }

    while(left < middle){ // если в левой части элементов оказалось больше, дописываем их в массив
        buff[i] = arr[left]; 
        left++; i++; 
    }

    while(right < size){ // если в правой части элементов оказалось больше, дописываем их в массив
        buff[i] = arr[right]; 
        right++; i++;
    }

    // переносим значение из буффера, в изнчальный массив
    for(size_t i = 0; i < size; i++){
        arr[i] = buff[i];
    }
}


/** @brief функция записи массива в файл
 * @param fileName имя файла
 * @param array массив, который будет записываться
 * @param size размер массива
 */
void arrInFile(const string& fileName, float* array, size_t size){
    ofstream openFile; // переменная файла
    openFile.open(fileName); // открываем файл по имени

    if(openFile.is_open() == true){ // если файл открыт
        for(size_t i = 0; i < size; i++){
        openFile << array[i] << " "; }
        openFile << endl; 
    }
    
    // закрываем файл после работы
    openFile.close();
}


/** @brief функция проверки на сортированный массив по возрастанию
 * @param array массив, в котором проходит проверка
 * @param size размер массива
 * @return true или false
 * @exception выбрасывает исключение вида invalid_argument, если массив пустой
 */
bool isSorted(float* array, size_t size){
    if(array == nullptr){ // проверка на пустой указатель
        throw invalid_argument("Массив не может быть пустым");
    } 

    for(size_t i = 1; i < size; i++){
        if(array[i - 1] > array[i]){
            return false;
        }
    } return true;
}