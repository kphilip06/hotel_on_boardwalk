#pragma once
#include <random>

template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(const T& val) : data(val), next(nullptr) {}
};

template <typename T>
class Monopoly {
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* current;
public:
    Monopoly() : head(nullptr), tail(nullptr), current(nullptr) {}

    T getCurrent() const {
        return current->data;
    }
    void append(T Value);
    void step();
    void randomMove();

};
template<typename T> void Monopoly<T>::append(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail -> next = newNode;
        tail = newNode;
    }
    newNode -> next = head;
}


template<typename T> void Monopoly<T>::step() {
    if (current == nullptr) {
        current = head;
    } else {
        current = current -> next;
    }
}

template<typename T> void Monopoly<T>::randomMove() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> die(1, 6);

    int num1 = die(gen);
    int num2 = die(gen);
    int roll = num1 + num2;

    std::cout << "You rolled a " << roll << std::endl;

    for (int i = 0; i < roll; i++) {
        step();
        std::cout << "You moved to " << getCurrent() << "!" << std::endl;
    }
}

