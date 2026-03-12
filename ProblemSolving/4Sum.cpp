/*
LEETCODE 18: 4SUM
Problem:
Given an integer array nums and an integer target, return all unique quadruplets
[a,b,c,d] such that:
1. a + b + c + d == target
2. Quadruplets must not be duplicates
3. Indices are all different
Example:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output:
[
  [-2,-1,1,2],
  [-2,0,0,2],
  [-1,0,0,1]
]
Approach:
1. Sort the array
2. Loop for first element i
3. Loop for second element j (j>i)
4. Two pointers (left, right) for remaining two elements
5. Skip duplicates
6. Store valid quadruplets in result
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> result;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n-3; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue; // skip duplicate i

        for(int j = i+1; j < n-2; j++)
        {
            if(j > i+1 && nums[j] == nums[j-1]) continue; // skip duplicate j

            int left = j+1;
            int right = n-1;

            while(left < right)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if(sum == target)
                {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;

                    while(left < right && nums[left] == nums[left-1]) left++; // skip duplicates
                    while(left < right && nums[right] == nums[right+1]) right--; // skip duplicates
                }
                else if(sum < target)
                    left++;
                else
                    right--;
            }
        }
    }

    return result;
}

int main()
{
    int n, target;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for(int i=0; i<n; i++)
        cin >> nums[i];

    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>> ans = fourSum(nums, target);

    cout << "Quadruplets:\n";
    for(auto &quad : ans)
    {
        for(int x : quad)
            cout << x << " ";
        cout << "\n";
    }
}
