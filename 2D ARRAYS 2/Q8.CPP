#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findOriginalArray(vector<int>& changed) {
    int n = changed.size();
    
    if (n % 2 != 0) {
        return {}; // Return empty array if changed has odd length
    }
    
    vector<int> original;
    unordered_map<int, int> count;
    
    // Count the frequency of each element in changed
    for (int num : changed) {
        count[num]++;
    }
    
    // Iterate over each element in changed
    for (int num : changed) {
        if (count[num] == 0) {
            continue; // Skip if num has been used already
        }
        
        int doubled = num * 2;
        
        // Check if the doubled value exists and has non-zero frequency
        if (count[doubled] == 0) {
            return {}; // Return empty array if doubled value is missing
        }
        
        // Update the frequency of num and doubled
        count[num]--;
        count[doubled]--;
        
        // Add num to the original array
        original.push_back(num);
    }
    
    return original;
}

int main() {
    vector<int> changed = {1, 3, 4, 2, 6, 8};
    
    vector<int> original = findOriginalArray(changed);
    
    cout << "Original array: ";
    for (int num : original) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

