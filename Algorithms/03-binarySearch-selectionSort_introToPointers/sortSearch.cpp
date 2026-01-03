#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void readNames(std::vector<std::string>& names) {
    std::ifstream ifs;
    std::string name;
    ifs.open("StudentNames.txt");

    if (!ifs.is_open()) {
        std::cout << "Could not open file" << std::endl;
        return ;
    }

    while (!ifs.eof()) {
        if (ifs.fail()) {
            std::cout << "Failed to reach end of file" << std::endl;
            break;
        }

        std::getline(ifs, name);
        names.push_back(name);
    }

    ifs.close();
}

void printAll(const std::vector<std::string>& names) {
    for (int i = 0; i < names.size(); i++) {
        std::cout << names.at(i) << std::endl;
    }
}

void selectionSort(std::vector<std::string>& names) {
    int minInd;
    std::string tmp;

    for (int i = 0; i < names.size() - 1; i++) {
        minInd = i;

        for (int j = i + 1; j < names.size(); j++) {
            if (names.at(j) < names.at(minInd)) {
                minInd = j;
            }
        }

        tmp = names.at(i);
        names.at(i) = names.at(minInd);
        names.at(minInd) = tmp;
    }
}

int binarySearch(const std::vector<std::string>& names, const std::string& searchName) {
    int head, tail, mid;
    head = 0;
    tail = names.size() - 1;

    while (head <= tail) {
        mid = (head + tail) / 2;
        if (searchName > names.at(mid)) {
            head = mid + 1;
        } else if (searchName < names.at(mid)) {
            tail = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    std::vector<std::string> students;
    std::string searchStudent;
    int i;

    readNames(students);
    printAll(students);

    std::cout << "----------------------" << std::endl;
    std::cout << "SORTED" << std::endl;
    std::cout << "----------------------" << std::endl;

    selectionSort(students);
    printAll(students);

    std::cout << "----------------------" << std::endl;
    std::cout << "Enter student name as follows: last, first" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::getline(std::cin, searchStudent);
    i = binarySearch(students, searchStudent);
    if (i != -1) {
        std::cout << searchStudent << " found at index " << i << "." << std::endl;
    } else {
        std::cout << "Student not found." << std::endl;
    }

    return 0;
}