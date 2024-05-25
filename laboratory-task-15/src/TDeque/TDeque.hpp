#ifndef TDEQUE_HPP
#define TDEQUE_HPP

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stdexcept>


// Шаблонный класс TDeque
template<typename T>
class TDeque {
protected:
    struct TDequeItem {
        T Info;                // Данные
        TDequeItem* next;      // Указатель на следующий элемент
        TDequeItem* prev;      // Указатель на предыдущий элемент

        TDequeItem(const T& info) : Info(info), next(nullptr), prev(nullptr) {}
    };

    TDequeItem *front, *rear;
    int size;

    void Erase();
    void Clone(const TDeque&);
    void DeleteItem(TDequeItem*);
    TDequeItem* PtrByIndex(unsigned) const;

public:
    TDeque();
    TDeque(const TDeque&);
    virtual ~TDeque();

    void InsFront(const T&);
    void InsRear(const T&);
    bool DelFront(T&);
    bool DelRear(T&);
    const TDeque& operator=(const TDeque&);
    const T& GetByIndex(unsigned) const;
    void SetByIndex(const T&, unsigned);
    void Browse(void(*)(T&));
    void Browse(void(*)(T)) const;
};

// Конструктор по умолчанию
template<typename T>
TDeque<T>::TDeque() : front(nullptr), rear(nullptr), size(0) {}

// Конструктор копирования
template<typename T>
TDeque<T>::TDeque(const TDeque& other) : front(nullptr), rear(nullptr), size(0) {
    Clone(other);
}

// Деструктор
template<typename T>
TDeque<T>::~TDeque() {
    Erase();
}

// Удаление всех элементов
template<typename T>
void TDeque<T>::Erase() {
    while (front) {
        DeleteItem(front);
    }
}

// Клонирование дека
template<typename T>
void TDeque<T>::Clone(const TDeque& other) {
    for (TDequeItem* item = other.front; item != nullptr; item = item->next) {
        InsRear(item->Info);
    }
}

// Удаление элемента по указателю
template<typename T>
void TDeque<T>::DeleteItem(TDequeItem* item) {
    if (item->prev) {
        item->prev->next = item->next;
    } else {
        front = item->next;
    }
    if (item->next) {
        item->next->prev = item->prev;
    } else {
        rear = item->prev;
    }
    delete item;
    --size;
}

// Указатель на элемент с заданным индексом
template<typename T>
typename TDeque<T>::TDequeItem* TDeque<T>::PtrByIndex(unsigned index) const {
    if (index >= size) return nullptr;
    TDequeItem* item = front;
    for (unsigned i = 0; i < index; ++i) {
        item = item->next;
    }
    return item;
}

// Включить элемент в голову дека
template<typename T>
void TDeque<T>::InsFront(const T& info) {
    TDequeItem* newItem = new TDequeItem(info);
    newItem->next = front;
    if (front) {
        front->prev = newItem;
    }
    front = newItem;
    if (!rear) {
        rear = front;
    }
    ++size;
}

// Включить элемент в хвост дека
template<typename T>
void TDeque<T>::InsRear(const T& info) {
    TDequeItem* newItem = new TDequeItem(info);
    newItem->prev = rear;
    if (rear) {
        rear->next = newItem;
    }
    rear = newItem;
    if (!front) {
        front = rear;
    }
    ++size;
}

// Исключить элемент из головы дека
template<typename T>
bool TDeque<T>::DelFront(T& info) {
    if (!front) return false;
    TDequeItem* oldFront = front;
    info = front->Info;
    front = front->next;
    if (front) {
        front->prev = nullptr;
    } else {
        rear = nullptr;
    }
    delete oldFront;
    --size;
    return true;
}

// Исключить элемент из хвоста дека
template<typename T>
bool TDeque<T>::DelRear(T& info) {
    if (!rear) return false;
    TDequeItem* oldRear = rear;
    info = rear->Info;
    rear = rear->prev;
    if (rear) {
        rear->next = nullptr;
    } else {
        front = nullptr;
    }
    delete oldRear;
    --size;
    return true;
}

// Оператор присваивания
template<typename T>
const TDeque<T>& TDeque<T>::operator=(const TDeque& other) {
    if (this != &other) {
        Erase();
        Clone(other);
    }
    return *this;
}

// Получить элемент по индексу
template<typename T>
const T& TDeque<T>::GetByIndex(unsigned index) const {
    TDequeItem* item = PtrByIndex(index);
    if (item) {
        return item->Info;
    }
    throw std::out_of_range("Index out of range");
}

// Изменить элемент по индексу
template<typename T>
void TDeque<T>::SetByIndex(const T& info, unsigned index) {
    TDequeItem* item = PtrByIndex(index);
    if (item) {
        item->Info = info;
    } else {
        throw std::out_of_range("Index out of range");
    }
}

// Просмотр с изменением элементов
template<typename T>
void TDeque<T>::Browse(void(*func)(T&)) {
    for (TDequeItem* item = front; item != nullptr; item = item->next) {
        func(item->Info);
    }
}

// Просмотр без изменения элементов
template<typename T>
void TDeque<T>::Browse(void(*func)(T)) const {
    for (TDequeItem* item = front; item != nullptr; item = item->next) {
        func(item->Info);
    }
}

#endif // TDEQUE_HPP
