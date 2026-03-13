/*HackerRank Problem: Counting Sort 1
Problem:
Given an array arr where each value is between 0 and 99,
count how many times each number appears.
Return an array of size 100 where:
index = number
value = frequency of that number
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> countingSort(vector<int> arr)
{
    vector<int> freq(100,0); // frequency array

    for(int i=0;i<arr.size();i++)
    {
        freq[arr[i]]++; // increase count
    }

    return freq;
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

    vector<int> result = countingSort(arr);

    cout<<"Frequency array:\n";

    for(int i=0;i<100;i++)
        cout<<result[i]<<" ";

}
