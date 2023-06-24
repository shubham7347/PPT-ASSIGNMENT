#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 5, 7, 8,1};
    int n = 5;
    bool hasDuplicates = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                hasDuplicates = true;
                break;
            }
        }

    }

    if (hasDuplicates) {
        cout << "true" <<endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}

