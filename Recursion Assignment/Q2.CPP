#include <iostream>
#include <stack>

bool isValid(std::string s) {
    std::stack<char> parentheses;
    std::stack<char> stars;

    for (char c : s) {
        if (c == '(') {
            parentheses.push(c);
        } else if (c == '*') {
            stars.push(c);
        } else {
            if (!parentheses.empty()) {
                parentheses.pop();
            } else if (!stars.empty()) {
                stars.pop();
            } else {
                return false;
            }
        }
    }

    while (!parentheses.empty() && !stars.empty()) {
        if (parentheses.top() > stars.top()) {
            return false;
        }
        parentheses.pop();
        stars.pop();
    }

    return parentheses.empty();
}

int main() {
    std::string s = "()";
    bool result = isValid(s);
    std::cout << "Output: " << std::boolalpha << result << std::endl;
    return 0;
}
