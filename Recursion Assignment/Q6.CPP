#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> findAnagrams(std::string s, std::string p) {
    std::vector<int> result;
    int n = s.size();
    int m = p.size();

    if (n < m) {
        return result;
    }

    std::unordered_map<char, int> targetFreq;
    std::unordered_map<char, int> windowFreq;

    for (char c : p) {
        targetFreq[c]++;
    }

    int left = 0;
    int right = 0;
    int matchCount = 0;

    while (right < n) {
        char currentChar = s[right];
        if (targetFreq.find(currentChar) != targetFreq.end()) {
            windowFreq[currentChar]++;
            if (windowFreq[currentChar] == targetFreq[currentChar]) {
                matchCount++;
            }
        }

        while (matchCount == targetFreq.size()) {
            if (right - left + 1 == m) {
                result.push_back(left);
            }

            char leftChar = s[left];
            if (targetFreq.find(leftChar) != targetFreq.end()) {
                windowFreq[leftChar]--;
                if (windowFreq[leftChar] < targetFreq[leftChar]) {
                    matchCount--;
                }
            }

            left++;
        }

        right++;
    }

    return result;
}

int main() {
    std::string s = "cbaebabacd";
    std::string p = "abc";
    std::vector<int> result = findAnagrams(s, p);
    std::cout << "Output: ";
    for (int index : result) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
    return 0;
}
