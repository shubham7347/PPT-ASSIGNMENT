#include <iostream>
#include <cmath>

using namespace std;

int arrangeCoins(int n) {
    // Solve for k using the quadratic formula
    // k(k + 1) / 2 <= n
    // k^2 + k - 2n <= 0
    // k = (-1 + sqrt(1 + 8n)) / 2
    double k = (-1 + sqrt(1 + 8 * (long long)n)) / 2;
    
    // The integer part of k represents the number of complete rows
    return static_cast<int>(k);
}

int main() {
    int n = 5;
    
    int completeRows = arrangeCoins(n);
    
    cout << "Number of complete rows: " << completeRows << endl;
    
    return 0;
}
