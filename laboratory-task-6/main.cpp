/*
Лабораторная работа №6
Шаблоны функций. Перегрузка функций.
Задание 1.
Разработать шаблон функции для обработки массивов с элементами простого арифметического типа и массивов, элементы которых – строки типа char*. Продемонстрировать использование этого шаблона для конкретных динамических массивов типа int, double, char*.
Для получения входных данных иметь три варианта:
непосредственный ввод и запись в текстовый файл;
генерирование с помощью датчика случайных чисел и запись в текстовый файл;
ввод из текстового файла, а вывод - в консоль.

Разработать шаблон функции, позволяющей в заданной последовательности найти элемент, в двоичном представлении которого наименьшее число нулей.
*/
#include <iostream>
#include <limits>
#include <bitset>
#include <cstring>

// Функция для подсчета числа нулей в числе
template <typename T>
int countZeros(T value) {
    std::bitset<sizeof(T) * 8> bits(value);
    return bits.count();
}

// Перегруженная функция для подсчета числа нулей в строке char*
int countZeros(const char* str) {
    int zerosCount = 0;
    while (*str != '\0') {
        zerosCount += (*str == '0');
        ++str;
    }
    return zerosCount;
}

template <typename T>
T findElementWithMinZeros(T* arr, size_t size) {
    if (size == 0) {
        std::cerr << "Error: Empty array\n";
        return T();
    }

    T minZerosElement = arr[0];
    int minZerosCount = countZeros(minZerosElement);

    for (size_t i = 1; i < size; ++i) {
        int zerosCount = countZeros(arr[i]);
        if (zerosCount < minZerosCount) {
            minZerosCount = zerosCount;
            minZerosElement = arr[i];
        }
    }

    return minZerosElement;
}

int main() {
    int intArray[] = { 5, 12, 6, 8, 10 };
    size_t intArraySize = sizeof(intArray) / sizeof(int);
    int resultInt = findElementWithMinZeros(intArray, intArraySize);
    std::cout << "Min Zeros Element (int): " << resultInt << std::endl;

    double doubleArray[] = { 3.14, 2.718, 1.618, 0.0 };
    size_t doubleArraySize = sizeof(doubleArray) / sizeof(double);
    double resultDouble = findElementWithMinZeros(doubleArray, doubleArraySize);
    std::cout << "Min Zeros Element (double): " << resultDouble << std::endl;

    const char* charArray[] = { "apple", "banana", "cherry", "date" };
    size_t charArraySize = sizeof(charArray) / sizeof(const char*);
    const char* resultChar = findElementWithMinZeros(charArray, charArraySize);
    std::cout << "Min Zeros Element (char*): " << resultChar << std::endl;

    return 0;
}
