#include <iostream>
#include <vector>

using namespace std;

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> ranges;
    int n = nums.size();
    long long prev = static_cast<long long>(lower) - 1;
    for (int i = 0; i <= n; i++) {
        long long curr = (i == n) ? static_cast<long long>(upper) + 1 : nums[i];
        if (prev + 2 == curr) {
            ranges.push_back(to_string(prev + 1));
        } else if (prev + 2 < curr) {
            ranges.push_back(to_string(prev + 1) + "->" + to_string(curr - 1));
        }
        prev = curr;
    }
    return ranges;
}

int main() {
    vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0;
    int upper = 99;
    vector<string> result = findMissingRanges(nums, lower, upper);
    cout << "Missing Ranges: " << endl;
    for (string range : result) {
        cout << range << endl;
    }
    return 0;
}
