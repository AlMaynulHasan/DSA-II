/*You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.
What is the longest sequence of successive songs where each song is unique?
Input
The first input line contains an integer n: the number of songs.
The next line has n integers k_1,k_2,\ldots,k_n: the id number of each song.
Output
Print the length of the longest sequence of unique songs.
Constraints
1 <= n <= 2*10^5
1 <= k_i <= 10^9
Example
Input:
8
1 2 1 3 2 7 4 2
Output:
5*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<long long,int> pos;
    long long x;
    int l = 0, ans = 0;
    for(int r = 0; r < n; r++) {
        cin >> x;
        if(pos.count(x))
            l = max(l, pos[x] + 1);
        pos[x] = r;
        ans = max(ans, r - l + 1);
    }
    cout << ans;
}
