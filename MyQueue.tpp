#include <vector>

template<typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr), count(0) {}

template<typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

template<typename T>
void Queue<T>::push(T data) {
    Node* node = new Node(data);
    if (tail != nullptr) {
        tail->next = node;
    }
    tail = node;
    if (head == nullptr) {
        head = node;
    }
    count++;
}

template<typename T>
T Queue<T>::pop() {
    if (empty()) throw std::underflow_error("Queue is empty");
    Node* temp = head;
    T data = head->data;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
    count--;
    return data;
}

template<typename T>
T Queue<T>::front() const {
    if (empty()) throw std::underflow_error("Queue is empty");
    return head->data;
}

template<typename T>
int Queue<T>::size() const {
    return count;
}

template<typename T>
bool Queue<T>::empty() const {
    return count == 0;
}

template<typename T>
void Queue<T>::move_to_rear() {
    if (size() > 1) {
        push(pop());
    }
}