#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    for (int i = 1; i < n; i++) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    bool result = canAttendMeetings(intervals);
    cout << "Can attend all meetings? " << (result ? "Yes" : "No") << endl;
    return 0;
}
