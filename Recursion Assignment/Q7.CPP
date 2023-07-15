#include <iostream>
#include <stack>

std::string decodeString(std::string s) {
    std::stack<int> numStack;
    std::stack<std::string> strStack;
    std::string currentString;
    int num = 0;

    for (char c : s) {
        if (std::isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '[') {
            numStack.push(num);
            strStack.push(currentString);
            num = 0;
            currentString = "";
        } else if (c == ']') {
            int repeatTimes = numStack.top();
            numStack.pop();
            std::string decodedString = "";
            for (int i = 0; i < repeatTimes; ++i) {
                decodedString += currentString;
            }
            currentString = strStack.top() + decodedString;
            strStack.pop();
        } else {
            currentString += c;
        }
    }

    return currentString;
}

int main() {
    std::string s = "3[a]2[bc]";
    std::string result = decodeString(s);
    std::cout << "Output: " << result << std::endl;
    return 0;
}
