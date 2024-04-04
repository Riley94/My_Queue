#include "MyQueue.h"

template<typename T>
int recursive_linear_search_last(const std::vector<T>& vec, T target, int index) {
    if (index < 0) return -1; // Base case: not found
    if (vec[index] == target) return index;
    return recursive_linear_search_last(vec, target, index - 1);
}

template<typename T>
int find_last_occurrence(const std::vector<T>& vec, T target) {
    return recursive_linear_search_last(vec, target, vec.size() - 1);
}

int main()
{
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    std::cout << "Queue size: " << q.size() << std::endl;
    std::cout << "Queue front: " << q.front() << std::endl;
    q.move_to_rear();
    std::cout << "Queue front after move_to_rear: " << q.front() << std::endl;
    q.pop();
    std::cout << "Queue size after pop: " << q.size() << std::endl;
    std::cout << "Queue front after pop: " << q.front() << std::endl;
    return 0;
}