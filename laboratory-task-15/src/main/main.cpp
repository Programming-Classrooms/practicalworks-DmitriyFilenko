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
    std::cout << std::endl;

    return 0;
}
