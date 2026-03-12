/*
QS PROBLEM: HackerRank - QuickSort 1 (Partition)
Task:
You are given an array. The first element is the pivot.
Partition the array so that:

    left  = elements less than pivot
    pivot = first element
    right = elements greater than or equal to pivot

Return a new array in the order:

    left + pivot + right

Important:
The relative order of elements must stay the same
(stable partition).

Example:
Input:
5
4 5 3 7 2

pivot = 4

left  = 3 2
right = 5 7

Output:
3 2 4 5 7
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> quickSort(vector<int> arr) {

    // QS: choose first element as pivot
    int pivot = arr[0];

    // QS: containers for partition
    vector<int> left;
    vector<int> right;

    // QS: partition elements based on pivot
    for(int i = 1; i < arr.size(); i++) {

        if(arr[i] < pivot)
            left.push_back(arr[i]);   // QS: smaller elements

        else
            right.push_back(arr[i]);  // QS: greater or equal elements
    }

    // QS: combine partitions
    vector<int> result;

    for(int x : left)
        result.push_back(x);

    result.push_back(pivot); // QS: pivot in middle

    for(int x : right)
        result.push_back(x);

    return result;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // QS: perform partition step
    vector<int> result = quickSort(arr);

    // QS: print result
    for(int x : result)
        cout << x << " ";

    return 0;
}
