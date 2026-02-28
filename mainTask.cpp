#include <iostream>
#include <cstdlib>
#include <chrono>
#include "workWithArrays.hpp" // модуль программы

/* автор программы - Лесков Н.Г
текст задания - https://github.com/ivtipm/Data-structures-and-algorithms/blob/main/current_plans/2026/2026_part_1.md*/

using namespace std;
using namespace chrono;

int main(){

    // рандомизируем значения перед генерацией
    srand(time(NULL));

    // задаём указатель массива, буффера обмена и количество переменных в нём
    size_t N = 100000;
    float* array, *buffer;
    
    array = createArray(N); // инициализируем массив
    buffer = createArray(N);
    array = fillArrayD(N, 10.5, 99.5);

    auto t0 = steady_clock::now(); // начинаем отсчёт времени выполнения участка кода
    mergeSort(array, buffer, N);
    auto t1 = steady_clock::now(); // конечная точка отсчёта
    
    arrInFile("newFile.txt", array, N);

    // преобразование времени (обычно наносекунды) в миллисекунды
    // delta - объект, хранящий время
    auto delta = duration_cast<milliseconds>(t1 - t0);
    cout << "time delta (milliseconds) " << delta.count();
    
    delete[] array;
    return 0;
}