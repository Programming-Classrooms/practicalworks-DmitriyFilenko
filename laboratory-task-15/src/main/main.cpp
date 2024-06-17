
#include "src/TDeque/TDeque.hpp"
#include <iostream>


void printInt(const int& value) {
    std::cout << value << " ";
}

void incrementInt(int& value) {
    value++;
}

int main() {
    TDeque<int> deque;

    deque.InsFront(1);
    deque.InsRear(2);
    deque.InsFront(0);
    deque.InsRear(3);

    std::cout << "Deque contents: ";
    deque.Browse(printInt);
    std::cout << std::endl;

    deque.Browse(incrementInt);

    std::cout << "Deque contents after increment: ";
    deque.Browse(printInt);
    std::cout << std::endl;

    int value;
    deque.DelFront(value);
    std::cout << "Deleted from front: " << value << std::endl;

    deque.DelRear(value);
    std::cout << "Deleted from rear: " << value << std::endl;

    std::cout << "Deque contents after deletions: ";
    deque.Browse(printInt);
#include <iostream>
#include "src/TDeque/TDeque.hpp"


// Функция для печати элементов дека
template<typename T>
void PrintItem(T& item) {
    std::cout << item << " ";
}

// Пример использования шаблонного класса TDeque
int main() {
    // Пример с целыми числами
    TDeque<int> intDeque;
    int32_t num3 = 20;
    intDeque.InsFront(10);
    intDeque.InsRear(num3);
    intDeque.InsFront(5);
    intDeque.InsRear(30);

    std::cout << "Integer Deque: ";
    intDeque.Browse(PrintItem);
    std::cout << std::endl;

    // Пример с char*
    TDeque<char*> strDeque;
    char str1[] = "hello";
    char str3[] = "deque";
    strDeque.InsFront(str1);
    strDeque.InsRear("world");
    strDeque.InsFront(str3);

    std::cout << "String Deque: ";
    strDeque.Browse([](char* str) { std::cout << str << " "; });
    std::cout << std::endl;

    return 0;
}
