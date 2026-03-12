/*
Problem: Lily's Homework (HackerRank)

Question:
Lily has an array of distinct integers.
She wants to make the array "beautiful".

An array is beautiful if the sum of |arr[i] - arr[i-1]| is minimum.

Observation:
The sum becomes minimum when the array is sorted.

So we need to find the minimum number of swaps required to transform
the array into:
1) Ascending sorted order
2) Descending sorted order

Then return the minimum swaps between these two cases.

Concept Used:
Minimum Swaps to Sort using Cycle Detection.

If a cycle length = k,
then swaps needed = k - 1.

Example:
Input:
4
2 5 3 1

Ascending target:
1 2 3 5

Cycle:
2 -> 5 -> 1 -> back

Cycle length = 3
Swaps = 3 - 1 = 2

Answer = 2
*/

#include <bits/stdc++.h>
using namespace std;

// Function to count minimum swaps to sort array in ascending order
int countSwaps(vector<int> arr) {

    int n = arr.size();

    // Pair array value with original index
    vector<pair<int,int>> v(n);

    for(int i = 0; i < n; i++) {
        v[i] = {arr[i], i};
    }

    // Sort by values
    sort(v.begin(), v.end());

    // Track visited nodes
    vector<bool> visited(n, false);

    int swaps = 0;

    for(int i = 0; i < n; i++) {

        // Already visited or already in correct position
        if(visited[i] || v[i].second == i)
            continue;

        int cycle = 0;
        int j = i;

        // Detect cycle
        while(!visited[j]) {
            visited[j] = true;
            j = v[j].second;
            cycle++;
        }

        // If cycle size > 1
        if(cycle > 1)
            swaps += cycle - 1;
    }

    return swaps;
}

// Main Lily's Homework logic
int lilysHomework(vector<int> arr) {

    vector<int> arr2 = arr;

    // Count swaps for ascending order
    int asc = countSwaps(arr);

    // Reverse array to simulate descending order
    reverse(arr2.begin(), arr2.end());

    int desc = countSwaps(arr2);

    // Return minimum swaps
    return min(asc, desc);
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = lilysHomework(arr);

    cout << result << endl;

    return 0;
}