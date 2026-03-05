/*Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.
Input
The first input line has an integer n: the size of the array.
The second line has n integers x_1,x_2,\dots,x_n: the array values.
Output
Print one integer: the maximum subarray sum.
Constraints
1 <= n <= 2 * 10^5
-10^9 <= x_i <= 10^9
Example
Input:
8
-1 3 -2 5 3 -5 2 2
Output:
9	*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    long long current = a[0], best = a[0];

    for(int i=1;i<n;i++){
        current = max(a[i], current + a[i]);
        best = max(best, current);
    }

    cout << best;
}