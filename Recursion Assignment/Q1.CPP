#include <iostream>
#include <string>
#include <numeric>

int minimumDeleteSum(std::string s1, std::string s2) {
    int m = s1.size();
    int n = s2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        dp[i][0] = dp[i - 1][0] + s1[i - 1];
    }

    for (int j = 1; j <= n; ++j) {
        dp[0][j] = dp[0][j - 1] + s2[j - 1];
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    std::string s1 = "sea";
    std::string s2 = "eat";
    int result = minimumDeleteSum(s1, s2);
    std::cout << "Output: " << result << std::endl;
    return 0;
}
