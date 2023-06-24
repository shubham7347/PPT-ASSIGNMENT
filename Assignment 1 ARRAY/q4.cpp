#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(std::vector<int>& digits) {
    int carry = 1; // Initialize carry to 1

    for (int i = digits.size() - 1; i >= 0; i--) {
        digits[i] += carry;
        carry = digits[i] / 10;
        digits[i] %= 10;
    }

    if (carry)
        digits.insert(digits.begin(), carry);

    return digits;
}

int main() {
    vector<int> digits = {1, 2, 3};
    vector<int> result = plusOne(digits);

    cout << "Output: ";
    for (int digit : result) {
        cout << digit << " ";
    }
    cout << endl;

    return 0;
}
