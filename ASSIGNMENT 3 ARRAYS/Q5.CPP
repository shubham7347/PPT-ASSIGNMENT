#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        } else {
            digits[i] = 0;
        }
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

int main() {
    vector<int> digits = {1, 2, 3};
    vector<int> result = plusOne(digits);
    cout << "Result: ";
    for (int digit : result) {
        cout << digit << " ";
    }
    cout << endl;
    return 0;
}
