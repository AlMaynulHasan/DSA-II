/*You have n coins with positive integer values. What is the smallest sum you cannot create using a subset of the coins?
Input
The first line has an integer n: the number of coins.
The second line has n integers x_1,x_2,\dots,x_n: the value of each coin.
Output
Print one integer: the smallest coin sum.
Constraints
1 <= n <= 2 * 10^5
1 <= x_i <= 10^9
Example
Input:
5
2 9 1 2 7
Output:
6*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long coins[n];
    for(int i = 0; i < n; i++) cin >> coins[i];
    sort(coins, coins + n);
    long long smallest_missing = 1;
    for(int i = 0; i < n; i++) {
        if(coins[i] > smallest_missing)
            break;
        smallest_missing += coins[i];
    }
    cout << smallest_missing << "\n";
}
