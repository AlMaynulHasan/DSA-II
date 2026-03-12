/*
Problem: Find the Median (HackerRank)
Question:
You are given an unsorted array of integers.
Your task is to find the median of the array.
Median:
The median is the middle element of a sorted array.
Important Note:
The array length is always odd.
Steps to Solve:
1. Read the size of the array (n).
2. Read the array elements.
3. Sort the array in ascending order.
4. Since n is odd, the median will be at index n/2.
5. Print arr[n/2].
Example:
Input:
7
0 1 2 4 6 5 3
After Sorting:
0 1 2 3 4 5 6
Median = element at index 7/2 = 3
Output:
3
*/

#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<int> arr) {
    // Sort the array
    sort(arr.begin(), arr.end());
    int n = arr.size();
    // Return the middle element
    return arr[n/2];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = findMedian(arr);
    cout << result << endl;
    return 0;
}