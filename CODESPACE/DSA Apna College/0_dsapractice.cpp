#include <iostream>
#include <algorithm>
using namespace std;

int findMinDifference(int arr[], int n, int m) {
    if (m == 0 || n == 0)
        return 0;

    sort(arr, arr + n);

    int minDifference = arr[m - 1] - arr[0];

    for (int i = 1; i + m - 1 < n; i++) {
        int currentDifference = arr[i + m - 1] - arr[i];
        minDifference = min(minDifference, currentDifference);
    }

    return minDifference;
}

int main() {
    int arr[] = { 3, 4, 1, 9, 56, 7, 9, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 5; // Number of students

    int result = findMinDifference(arr, n, m);
    cout << "Minimum difference after chocolate distribution: " << result << endl;

    return 0;
}
