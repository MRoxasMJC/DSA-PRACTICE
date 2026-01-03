#include <iostream>
#include "stack.h"


int main() {
    Stack<int> nums;
    int top;

    nums.push(5);
    nums.push(10);
    nums.push(15);
    nums.printAll();

    top = nums.top();
    std::cout << "----------------------" << std::endl;
    std::cout << "TOP ELEMENT: " << top << std::endl;
    std::cout << "----------------------" << std::endl;

    nums.pop();
    std::cout << "----------------------" << std::endl;
    std::cout << "POPPING:" << std::endl;
    nums.printAll();
    std::cout << "----------------------" << std::endl;


    return 0;
}
