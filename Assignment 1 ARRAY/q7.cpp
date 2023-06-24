#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int right = 0;

    while (right < n) {
        if (nums[right] != 0) {
            swap(nums[left], nums[right]);
            left++;
        }
        right++;
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);

    for (int num : nums) {
        cout << num << " ";
    }
    
    return 0;
}
