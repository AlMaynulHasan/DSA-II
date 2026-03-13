/*
HackerRank Problem: Counting Sort 2
Problem:
You are given an array arr where each value is between 0 and 99.
Using Counting Sort idea, return the sorted array.
Instead of directly sorting using built-in sort(),
we count how many times each number appears and then
reconstruct the sorted array.
Example:
Input:
5
1 1 3 2 1
Frequency:
1 -> 3 times
2 -> 1 time
3 -> 1 time
Output:
1 1 1 2 3
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> countingSort(vector<int> arr)
{
    vector<int> freq(100,0); // frequency array (0-99)

    // Step 1: count frequency
    for(int i=0;i<arr.size();i++)
    {
        freq[arr[i]]++;
    }

    // Step 2: rebuild sorted array
    vector<int> result;

    for(int i=0;i<100;i++)
    {
        while(freq[i] > 0)
        {
            result.push_back(i);
            freq[i]--;
        }
    }

    return result;
}

int main()
{
    int n;

    cout<<"Enter size: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<int> sorted = countingSort(arr);

    cout<<"Sorted array:\n";

    for(int x : sorted)
        cout<<x<<" ";
}
