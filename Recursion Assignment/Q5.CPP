#include <iostream>
#include <vector>

int compress(std::vector<char>& chars) {
    int n = chars.size();
    if (n <= 1) {
        return n;
    }

    int writeIndex = 0;
    int count = 1;

    for (int i = 1; i < n; ++i) {
        if (chars[i] == chars[i - 1]) {
            ++count;
        } else {
            chars[writeIndex++] = chars[i - 1];
            if (count > 1) {
                std::string countStr = std::to_string(count);
                for (char c : countStr) {
                    chars[writeIndex++] = c;
                }
            }
            count = 1;
        }
    }

    chars[writeIndex++] = chars[n - 1];
    if (count > 1) {
        std::string countStr = std::to_string(count);
        for (char c : countStr) {
            chars[writeIndex++] = c;
        }
    }

    return writeIndex;
}

int main() {
    std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int result = compress(chars);
    std::cout << "Output: " << result << std::endl;
    std::cout << "Modified array: ";
    for (int i = 0; i < result; ++i) {
        std::cout << chars[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
