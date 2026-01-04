#include <iostream>
#include "simpleQueue.h"

int main() {
    Queue<int> nums;

    if (nums.isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
    }

    nums.enqueue(5);
    nums.enqueue(3);
    nums.enqueue(2);
    nums.enqueue(1);
    nums.printAll();

    if (nums.isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
    }

    std::cout << "Front: " << nums.front() << std::endl;
    nums.dequeue();
    std::cout << "Front: " << nums.front() << std::endl;
    nums.dequeue();
    std::cout << "Front: " << nums.front() << std::endl;
    nums.printAll();



    return 0;
}