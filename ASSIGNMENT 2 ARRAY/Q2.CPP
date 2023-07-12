#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int distributeCandies(vector<int>& candyType) {
    unordered_set<int> uniqueCandy;
    int maxCandies = candyType.size() / 2;
    for (int candy : candyType) {
        uniqueCandy.insert(candy);
        if (uniqueCandy.size() == maxCandies) {
            break;
        }
    }
    return uniqueCandy.size();
}

int main() {
    vector<int> candyType = {1, 1, 2, 2, 3, 3};
    int result = distributeCandies(candyType);
    cout << "Max number of different candies: " << result << endl;
    return 0;
}
