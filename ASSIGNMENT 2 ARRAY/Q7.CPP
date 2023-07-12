#include <iostream>
#include <vector>

using namespace std;

bool isMonotonic(vector<int>& nums) {
    bool increasing = true;
    bool decreasing = true;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            decreasing = false;
        }
        if (nums[i] < nums[i - 1]) {
            increasing = false;
        }
    }
    return increasing || decreasing;
}

int main() {
    vector<int> nums = {1, 2, 2, 3};
    bool result = isMonotonic(nums);
    cout << "Is the given array monotonic? " << (result ? "Yes" : "No") << endl;
    return 0;
}
