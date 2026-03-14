#include <iostream>
#include <cstdlib>
#include <chrono>
#include <string>
#include "workWithArrays.hpp" // модуль программы

/* автор программы - Лесков Н.Г
текст задания - https://github.com/ivtipm/Data-structures-and-algorithms/blob/main/current_plans/2026/2026_part_1.md*/

using namespace std;
using namespace chrono; // библиотека времени

int main(){

    // рандомизируем значения перед генерацией
    srand(time(NULL));

    // задаём указатель массива, буффера обмена и количество переменных в нём
    size_t N = 100000;
    float number = 1500.0; // число для поиска
    float* array, *buffer;
    string fileName = "bestArray.txt";
    
    array = createArray(N); // инициализируем массив
    buffer = createArray(N); // создаём буфер для файла
    array = fillSorted(N); // заполнение массива отсртированным
    array[N - 1] = number;

    auto t0 = steady_clock::now(); // начинаем отсчёт времени выполнения участка кода
    linearSearch(array, N, number);
    auto t1 = steady_clock::now(); // конечная точка отсчёта
    arrInFile(fileName, array, N); // запись в файл массива


    // преобразование времени (обычно наносекунды) в миллисекунды
    // delta - объект, хранящий время
    auto delta = duration_cast<milliseconds>(t1 - t0);
    cout << "time delta (milliseconds) " << delta.count() << endl;


    // проверка бинарного поиска
    cout << format("Искомое число {}, находится на {} месте", number, binarSearch(array, N, number));
    
    delete[] array; // очищаем память
    delete[] buffer; // очищаем буфер
    return 0;
}