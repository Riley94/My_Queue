#pragma once
#include <iostream>

template <typename T>
class MyQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int count;

public:
    MyQueue();
    ~MyQueue();
    void push(T data);
    T pop();
    T front() const;
    int size() const;
    bool empty() const;
    void move_to_rear();
};

#include "MyQueue.tpp"
