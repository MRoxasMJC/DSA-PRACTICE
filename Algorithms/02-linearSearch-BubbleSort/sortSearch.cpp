#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// TODO: Search for a specific name using linear search
// TODO: Sort the name in ascending and descending order using bubble sort

// this function reads a file and pushes the files contents to the vector
void readFile(std::vector<std::string>& names, std::string fileName, std::ifstream& fs) {
    std::string someText;

    std::cout << "Opening file" << std::endl;
    fs.open(fileName);

    if (!fs.is_open()) {
        std::cout << "Could not open file" << std::endl;
        return;
    }

    while (!fs.eof()) {
        if (fs.fail()) {
            std::cout << "Failure. End of file not reached" << std::endl;
            break;
        }

        std::getline(fs, someText);
        // std::cout << someText << std::endl;
        names.push_back(someText);
    }

    fs.close();
}
void displayNames(std::vector<std::string>& names) {
    for (int i = 0; i < names.size(); i++) {
        std::cout << i + 1 << " " << names.at(i) << std::endl;
    }
}
void bubbleSort(std::vector<std::string>& names) {
    for (int i = 1; i < names.size(); i++) {
        for (int j = 1 ; j < names.size(); j++) {
            if (names.at(j - 1) > names.at(j)) {
                std::string tmp = names.at(j);
                names.at(j) = names.at(j - 1);
                names.at(j - 1) = tmp;
            }
        }
    }
}

int main() {
    std::ifstream namesInp;
    std::vector<std::string> studentNames(0);

    readFile(studentNames, "C:\\Users\\melvi\\Dev\\projects\\cpp-projects\\02-linearSearch-BubbleSort\\StudentNames.txt", namesInp);
    bubbleSort(studentNames);
    displayNames(studentNames);

    return 0;
}
