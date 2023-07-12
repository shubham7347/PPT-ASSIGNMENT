#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> duplicates;
    
    for (int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;
        
        if (nums[index] < 0) {
            duplicates.push_back(index + 1);
        } else {
            nums[index] = -nums[index];
        }
    }
    
    return duplicates;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    
    vector<int> duplicateIntegers = findDuplicates(nums);
    
    cout << "Duplicate integers: ";
    for (int num : duplicateIntegers) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
