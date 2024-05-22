#ifndef TDEQUE_HPP
#define TDEQUE_HPP

#include <iostream>

template <typename T>
class TDeque {
protected:
    struct TDequeItem {
        T Info; // данные
        TDequeItem* next; // указатель на следующий элемент
        TDequeItem* prev; // указатель на предыдущий элемент
    };

    TDequeItem* front; // указатель на первый элемент
    TDequeItem* rear; // указатель на последний элемент
    int size; // количество элементов в деке

    void Erase(); // удаление всех элементов
    void Clone(const TDeque&); // клонирование дека
    void DeleteItem(TDequeItem*); // удаление элемента по указателю
    TDequeItem* PtrByIndex(unsigned) const; // указатель на элемент с заданным индексом

public:
    TDeque(); // конструктор
    TDeque(const TDeque&); // конструктор копирования
    virtual ~TDeque(); // деструктор

    void InsFront(T); // включить элемент в голову дека
    void InsRear(T); // включить элемент в хвост дека
    bool DelFront(T&); // исключить элемент из головы дека
    bool DelRear(T&); // исключить элемент из хвоста дека

    const TDeque& operator=(const TDeque&); // оператор присваивания

    const T& GetByIndex(unsigned) const; // получить элемент по индексу
    void SetByIndex(T, unsigned); // изменить элемент по индексу

    void Browse(void(*)(T&)); // просмотр с изменением элементов
    void Browse(void(*)(const T&)) const; // просмотр без изменения элементов

    int Size() const { return size; } // получение размера дека
};

#endif // TDEQUE_HPP
