#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> convertTo2DArray(vector<int>& original, int m, int n) {
    int size = original.size();
    
    if (size != m * n) {
        return {}; // Return empty 2D array if it is impossible to construct
    }
    
    vector<vector<int>> result(m, vector<int>(n, 0));
    
    for (int i = 0; i < size; i++) {
        int row = i / n;
        int col = i % n;
        result[row][col] = original[i];
    }
    
    return result;
}

int main() {
    vector<int> original = {1, 2, 3, 4};
    int m = 2;
    int n = 2;
    
    vector<vector<int>> twoDArray = convertTo2DArray(original, m, n);
    
    cout << "Constructed 2D array: " << endl;
    for (const auto& row : twoDArray) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}