#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
// An input string is valid if:
//
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

// my solution 1
bool isValid(std::string s) {
    std::vector<char> chars(0);
    std::unordered_map<char, char> match = {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };

    for (int i = 0; i < s.size(); i++) {
        auto it = match.find(s.at(i));
        if (s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{') {
            chars.push_back(s.at(i));
        } else if ((!chars.empty() && it != match.end()) && (it->second == chars.at(chars.size() - 1))) {
                chars.pop_back();
        } else {
            return false;
        }
    }

    return chars.size() == 0;
}

// my solution 2
bool isValid2(std::string s) {
    std::stack<char> chars;

    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{') {
            chars.push(s.at(i));
        } else {
            if (chars.size() == 0) {
                return false;
            }
            else if (s.at(i) == ')' && chars.top() == '('
                || s.at(i) == ']' && chars.top() == '['
                || s.at(i) == '}' && chars.top() == '{'
            ) {
                chars.pop();
            } else {
                return false;
            }
        }
    }

     return chars.empty();
}


int main() {
    std::string s1, s2, s3, s4, s5;
    s1 = "()"; // true
    s2 = "()[]{}"; // true
    s3 = "(]"; // false
    s4 = "([])"; // true
    s5 = "([)]"; // false

    // std::cout << isValid(s1) << std::endl;
    // std::cout << isValid(s2) << std::endl;
    // std::cout << isValid(s3) << std::endl;
    // std::cout << isValid(s4) << std::endl;
    // std::cout << isValid(s5) << std::endl;
    // std::cout << isValid("){") << std::endl;
    // std::cout << isValid("]") << std::endl;
    std::cout << isValid2("]") << std::endl;


return 0;
}