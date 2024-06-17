#include "TDeque.hpp"

template <typename T>
TDeque<T>::TDeque() : front(nullptr), rear(nullptr), size(0) {}

template <typename T>
TDeque<T>::TDeque(const TDeque& other) : front(nullptr), rear(nullptr), size(0) {
    Clone(other);
}

template <typename T>
TDeque<T>::~TDeque() {
    Erase();
}

template <typename T>
void TDeque<T>::Erase() {
    while (front) {
        DeleteItem(front);
    }
}

template <typename T>
void TDeque<T>::Clone(const TDeque& other) {
    TDequeItem* temp = other.front;
    while (temp) {
        InsRear(temp->Info);
        temp = temp->next;
    }
}

template <typename T>
void TDeque<T>::DeleteItem(TDequeItem* item) {
    if (!item) return;
    if (item->prev) item->prev->next = item->next;
    if (item->next) item->next->prev = item->prev;
    if (item == front) front = item->next;
    if (item == rear) rear = item->prev;
    delete item;
    size--;
}

template <typename T>
typename TDeque<T>::TDequeItem* TDeque<T>::PtrByIndex(unsigned index) const {
    if (index >= size) return nullptr;
    TDequeItem* temp = front;
    for (unsigned i = 0; i < index; ++i) {
        temp = temp->next;
    }
    return temp;
}

template <typename T>
void TDeque<T>::InsFront(T info) {
    TDequeItem* newItem = new TDequeItem{info, front, nullptr};
    if (front) front->prev = newItem;
    front = newItem;
    if (!rear) rear = front;
    size++;
}

template <typename T>
void TDeque<T>::InsRear(T info) {
    TDequeItem* newItem = new TDequeItem{info, nullptr, rear};
    if (rear) rear->next = newItem;
    rear = newItem;
    if (!front) front = rear;
    size++;
}

template <typename T>
bool TDeque<T>::DelFront(T& info) {
    if (!front) return false;
    TDequeItem* temp = front;
    info = temp->Info;
    front = front->next;
    if (front) front->prev = nullptr;
    else rear = nullptr;
    delete temp;
    size--;
    return true;
}

template <typename T>
bool TDeque<T>::DelRear(T& info) {
    if (!rear) return false;
    TDequeItem* temp = rear;
    info = temp->Info;
    rear = rear->prev;
    if (rear) rear->next = nullptr;
    else front = nullptr;
    delete temp;
    size--;
    return true;
}

template <typename T>
const TDeque<T>& TDeque<T>::operator=(const TDeque& other) {
    if (this == &other) return *this;
    Erase();
    Clone(other);
    return *this;
}

template <typename T>
const T& TDeque<T>::GetByIndex(unsigned index) const {
    TDequeItem* item = PtrByIndex(index);
    if (item) return item->Info;
    throw std::out_of_range("Index out of range");
}

template <typename T>
void TDeque<T>::SetByIndex(T info, unsigned index) {
    TDequeItem* item = PtrByIndex(index);
    if (item) item->Info = info;
    else throw std::out_of_range("Index out of range");
}

template <typename T>
void TDeque<T>::Browse(void(*func)(T&)) {
    TDequeItem* temp = front;
    while (temp) {
        func(temp->Info);
        temp = temp->next;
    }
}

template <typename T>
void TDeque<T>::Browse(void(*func)(const T&)) const {
    TDequeItem* temp = front;
    while (temp) {
        func(temp->Info);
        temp = temp->next;
    }
}
