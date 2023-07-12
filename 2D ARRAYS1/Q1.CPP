#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    unordered_set<int> set1(arr1.begin(), arr1.end());
    unordered_set<int> set2(arr2.begin(), arr2.end());
    vector<int> result;
    
    for (int num : arr3) {
        if (set1.count(num) && set2.count(num)) {
            result.push_back(num);
        }
    }
    
    return result;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 5, 7, 9};
    vector<int> arr3 = {1, 3, 4, 5, 8};
    
    vector<int> result = arraysIntersection(arr1, arr2, arr3);
    
    cout << "Common elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
