#include "LinkedList.hpp"


/*===========================================================================
============================ Конструкторы ===================================
===========================================================================*/

LinkedList::LinkedList() {
    head = NULL;
}

LinkedList::LinkedList(const LinkedList& obj) {
    if (obj.head == NULL) {
        head = NULL;
    }
    else {
        head = new Node(obj.head->value);
        Node* current = head;
        Node* objHead = obj.head;
        Node* currentObj = objHead;
        while (currentObj->next != NULL) {
            current->next = new Node(currentObj->next->value);
            currentObj = currentObj->next;
            current = current->next;
        }
    }
}

/*===========================================================================
============================== Деструктор ===================================
===========================================================================*/

LinkedList::~LinkedList() {
    Node* next = head;

    while (next) {
        Node* deleteMe = next;
        next = next->next;
        delete deleteMe;
    }
}

/*===========================================================================
========================== Добавление элемента ==============================
===========================================================================*/

void LinkedList::addValue(int val) {
    Node* n = new Node(val,head);
    head = n;
}

/*===========================================================================
=========================== Удаление элемента ===============================
===========================================================================*/

int LinkedList::popValue() {
    Node* node = head;
    if (node == nullptr){
        return -1;
    }
    int temp = node->value;
    head = head->next;
    delete node;
    return temp;
}

/*===========================================================================
=========================== Метод копирования ===============================
===========================================================================*/

LinkedList& LinkedList::Clone(const LinkedList& Rhs) {
    if (this == &Rhs){
        return *this;
    }
    if (Rhs.head == NULL) {
        head = NULL;
    }
    else {
        head = new Node(Rhs.head->value);
        Node* current = head;
        Node* objHead = Rhs.head;
        Node* currentObj = objHead;
        while (currentObj->next != NULL) {
            current->next = new Node(currentObj->next->value);
            currentObj = currentObj->next;
            current = current->next;
        }
    }
    return *this;
}

/*===========================================================================
========================= Вставка с сортировкой =============================
===========================================================================*/

void LinkedList::insertSorted(int val) {
    Node* newNode = new Node(val);
    if (!head || head->value >= val) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next && current->next->value < val) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

/*===========================================================================
============================== Вывод списка =================================
===========================================================================*/

void LinkedList::print() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << '\n';
}

/*===========================================================================
============================ Поиск по элементу ==============================
===========================================================================*/

int LinkedList::search(int val) {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->value == val) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }

/*===========================================================================
=================== Проход по списку с изменением значений ==================
===========================================================================*/

    void LinkedList::modifyValuesManually() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "Enter new value for element " << current->value << ": ";
            std::cin >> current->value;
            current = current->next;
        }
    }

/*===========================================================================
===================== Удаление элемента по значению =========================
===========================================================================*/

    void LinkedList::removeByValue(int val) {
        if (!head){
            return;
        }
        if (head->value == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->value != val) {
            current = current->next;
        }

        if (current->next == nullptr)
            return;

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

/*===========================================================================
======================= Добавление элемента в начало ========================
===========================================================================*/

    void LinkedList::addValueAtBegin(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

/*===========================================================================
=============================== Очистка списка ==============================
===========================================================================*/

void LinkedList::clear() {
        Node* next = head;

        while (next) {
            Node* deleteMe = next;
            next = next->next;
            delete deleteMe; 
        }
        head = nullptr;
    }