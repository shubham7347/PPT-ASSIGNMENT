#include <iostream>
#include <vector>

using namespace std;

int maxCount(int m, int n, vector<vector<int>>& ops) {
    int minRow = m;
    int minCol = n;
    
    for (const auto& op : ops) {
        minRow = min(minRow, op[0]);
        minCol = min(minCol, op[1]);
    }
    
    return minRow * minCol;
}

int main() {
    int m = 3;
    int n = 3;
    vector<vector<int>> ops = {{2, 2}, {3, 3}};
    
    int maxIntegers = maxCount(m, n, ops);
    
    cout << "Number of maximum integers: " << maxIntegers << endl;
    
    return 0;
}
