#include <iostream>
#include "LList.h"

int main() {
    LList<int> nums;
    nums.insert(2);
    nums.insert(4);
    nums.insert(3);
    nums.insert(0);
    nums.insert(1);

    nums.printAll();


    return 0;
}
