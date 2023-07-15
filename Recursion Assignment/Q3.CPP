#include <iostream>
#include <string>
#include <vector>

int minDistance(std::string word1, std::string word2) {
    int m = word1.size();
    int n = word2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        dp[i][0] = i;
    }

    for (int j = 1; j <= n; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    return dp[m][n];
}

int main() {
    std::string word1 = "sea";
    std::string word2 = "eat";
    int result = minDistance(word1, word2);
    std::cout << "Output: " << result << std::endl;
    return 0;
}
