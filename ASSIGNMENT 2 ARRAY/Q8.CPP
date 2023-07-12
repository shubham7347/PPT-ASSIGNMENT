#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumDifference(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int minScore = nums[n - 1] - nums[0];
    for (int i = 0; i < n - 1; i++) {
        int high = max(nums[i] + k, nums[n - 1] - k);
        int low = min(nums[i + 1] - k, nums[0] + k);
        minScore = min(minScore, high - low);
    }
    return minScore;
}

int main() {
    vector<int> nums = {1};
    int k = 0;
    int result = minimumDifference(nums, k);
    cout << "Minimum score: " << result << endl;
    return 0;
}
