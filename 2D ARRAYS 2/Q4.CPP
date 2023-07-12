#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> findDisappearedNumbers(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    
    vector<int> missingFromNums1;
    vector<int> missingFromNums2;
    
    for (int num : nums1) {
        if (!set2.count(num)) {
            missingFromNums2.push_back(num);
        }
    }
    
    for (int num : nums2) {
        if (!set1.count(num)) {
            missingFromNums1.push_back(num);
        }
    }
    
    return {missingFromNums1, missingFromNums2};
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};
    
    vector<vector<int>> answer = findDisappearedNumbers(nums1, nums2);
    
    cout << "Distinct integers in nums1 not present in nums2: ";
    for (int num : answer[0]) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Distinct integers in nums2 not present in nums1: ";
    for (int num : answer[1]) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}