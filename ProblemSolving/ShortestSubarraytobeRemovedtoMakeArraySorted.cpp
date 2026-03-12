#include <bits/stdc++.h>
using namespace std;

/*
LEETCODE 1574
Shortest Subarray to be Removed to Make Array Sorted

Problem:
Given an integer array arr.
Remove a contiguous subarray (can be empty) so that the remaining
array becomes non-decreasing.

Return the minimum length of the subarray that must be removed.

Example:
Input:
1 2 3 10 4 2 3 5

Output:
3

Explanation:
Remove [10,4,2]
Remaining array:
1 2 3 3 5  -> sorted
*/


int shortestSubarrayRemove(vector<int>& arr)
{
    int n = arr.size();

    // STEP 1: find longest sorted prefix
    int left = 0;

    while(left + 1 < n && arr[left] <= arr[left+1])
        left++;

    // If whole array already sorted
    if(left == n-1)
        return 0;

    // STEP 2: find longest sorted suffix
    int right = n-1;

    while(right > 0 && arr[right-1] <= arr[right])
        right--;

    /*
    Possible answers initially:

    Remove right part
    OR
    Remove left part
    */

    int ans = min(n-left-1 , right);

    /*
    STEP 3: try merging prefix and suffix
    using two pointers
    */

    int i = 0;
    int j = right;

    while(i <= left && j < n)
    {
        if(arr[i] <= arr[j])
        {
            // middle part can be removed
            ans = min(ans , j-i-1);
            i++;
        }
        else
        {
            j++;
        }
    }

    return ans;
}


int main()
{
    int n;

    cout<<"Enter array size: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter array elements: ";

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int result = shortestSubarrayRemove(arr);

    cout<<"Minimum subarray length to remove: "<<result;

}
