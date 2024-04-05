template<typename T>
MyQueue<T>::MyQueue() : head(nullptr), tail(nullptr), count(0) {}

template<typename T>
MyQueue<T>::MyQueue(T data) : head(nullptr), tail(nullptr), count(0) {
    push(data);
}

template<typename T>
MyQueue<T>::~MyQueue() {
    while (!empty()) {
        pop();
    }
}

template<typename T>
void MyQueue<T>::push(T data) {
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
T MyQueue<T>::pop() {
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
T MyQueue<T>::front() const {
    if (empty()) throw std::underflow_error("Queue is empty");
    return head->data;
}

template<typename T>
int MyQueue<T>::size() const {
    return count;
}

template<typename T>
bool MyQueue<T>::empty() const {
    return count == 0;
}

template<typename T>
void MyQueue<T>::move_to_rear() {
    if (size() > 1) {
        push(pop());
    }
}
