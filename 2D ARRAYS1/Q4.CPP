#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Sort the array in ascending order
    
    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2) {
        sum += nums[i]; // Sum the minimum element of each pair
    }
    
    return sum;
}

int main() {
    vector<int> nums = {1, 4, 3, 2};
    
    int maxSum = arrayPairSum(nums);
    
    cout << "Maximized sum: " << maxSum << endl;
    
    return 0;
}
