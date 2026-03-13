/*
HackerRank Problem: The Full Counting Sort

Problem:
You are given n pairs of data.
Each pair contains:
    integer x
    string s

Example input line:
x s

Your task:
Sort the strings based on integer x using Counting Sort.

Special Rule:
For the FIRST HALF of the input array,
replace the string with "-".

Also the sorting must be STABLE.
That means if two integers are equal,
their original order must be preserved.

Example:

Input
4
0 ab
1 cd
0 ef
1 gh

First half strings replaced:

0 -
1 -
0 ef
1 gh

After counting sort:

0 -
0 ef
1 -
1 gh

Output
- ef - gh
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<string>> bucket(100);

    for(int i = 0; i < n; i++)
    {
        int x;
        string s;
        cin >> x >> s;

        if(i < n/2)
            s = "-";

        bucket[x].push_back(s);
    }

    for(int i = 0; i < 100; i++)
    {
        for(string s : bucket[i])
        {
            cout << s << " ";
        }
    }

    return 0;
}
