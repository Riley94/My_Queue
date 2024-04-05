#include "MyQueue.h"
#include <vector>
#include <iostream>
#include <list>

template<typename T>
int recursive_linear_search(const std::vector<T>& vec, T target, int index) {
    if (index < 0) return -1; // Base case: not found
    if (vec[index] == target) return index;
    return recursive_linear_search(vec, target, index - 1);
}

template<typename T>
int find_last(const std::vector<T>& vec, T target) {
    return recursive_linear_search(vec, target, vec.size() - 1);
}

void insertion_sort(std::list<int>& list) {
    
    if (list.empty()) {
        return; // The list is empty
    }

    for (auto it = ++list.begin(); it != list.end(); ++it) {
        int key = *it;
        auto j = it;
        auto k = std::prev(it);

        // Move elements greater than key, one ahead of their current position
        while (j != list.begin() && key < *k) {
            *j = *k;
            --j;
            --k;
        }
        *j = key;
    }
}


int main()
{
    MyQueue<int> q(1);

    for (int i = 2; i <= 10; i++) {
        q.push(i);
    }
    
    std::cout << "Queue size: " << q.size() << std::endl;
    std::cout << "Queue front: " << q.front() << std::endl;
    q.move_to_rear();
    std::cout << "Queue front after move_to_rear: " << q.front() << std::endl;
    q.pop();
    std::cout << "Queue size after pop: " << q.size() << std::endl;
    std::cout << "Queue front after pop: " << q.front() << std::endl;

    std::list<int> myList = {4, 2, 5, 3, 1};

    insertion_sort(myList);

    for (int i : myList) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    return 0;
}
