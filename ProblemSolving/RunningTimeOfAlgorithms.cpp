/*HackerRank Problem: Running Time of Algorithms
Problem:
You are given an array of integers. The array is sorted using the
Insertion Sort algorithm.
Every time an element is shifted to the right during the sorting
process, it is counted as a "shift".
Your task:
Count the total number of shifts that occur while sorting the array
using insertion sort.
Example:
Input:
5
2 1 3 1 2
Insertion sort process:
2 1 3 1 2
1 2 3 1 2   shift = 1
1 2 3 1 2   shift = 0
1 1 2 3 2   shift = 2
1 1 2 2 3   shift = 1
Total shifts = 4 */

#include <bits/stdc++.h>
using namespace std;

int runningTime(vector<int> arr) {

    int n = arr.size();
    int shifts = 0;  // counts how many shifts happen

    // insertion sort algorithm
    for(int i = 1; i < n; i++) {

        int key = arr[i];  // current element
        int j = i - 1;

        // move larger elements to the right
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j]; // shift element
            j--;
            shifts++;          // count shift
        }

        // place key in correct position
        arr[j+1] = key;
    }

    return shifts;
}

int main() {

    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int result = runningTime(arr);

    cout << "Total shifts: " << result << endl;

    return 0;
}
