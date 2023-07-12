#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findLHS(vector<int>& nums) {
    unordered_map<int, int> count;
    int maxLength = 0;
    for (int num : nums) {
        count[num]++;
        if (count.count(num + 1)) {
            maxLength = max(maxLength, count[num] + count[num + 1]);
        }
        if (count.count(num - 1)) {
            maxLength = max(maxLength, count[num] + count[num - 1]);
        }
    }
    return maxLength;
}

int main() {
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    int result = findLHS(nums);
    cout << "Length of longest harmonious subsequence: " << result << endl;
    return 0;
}
