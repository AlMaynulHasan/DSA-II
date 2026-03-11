/*Consider an array of numeric strings where each string is a positive number with anywhere from  to  digits. Sort the array's elements in non-decreasing, or ascending order of their integer values and return the sorted array.
Example
Return the array ['1', '3', '150', '200'].
Function Description
Complete the bigSorting function in the editor below.
bigSorting has the following parameter(s):
string unsorted[n]: an unsorted array of integers as strings
Returns
string[n]: the array sorted in numerical order
Input Format
The first line contains an integer, , the number of strings in .
Each of the  subsequent lines contains an integer string, .
Constraints
Each string is guaranteed to represent a positive integer.
There will be no leading zeros.
The total number of digits across all strings in  is between  and  (inclusive).

Sample Input 0
31415926535897932384626433832795
1
3
10
3
5
Sample Output 0
1
3
3
5
10
31415926535897932384626433832795
Explanation 0
The initial array of strings is . When we order each string by the real-world integer value it represents, we get:
We then print each value on a new line, from smallest to largest.*/

#include <bits/stdc++.h>
using namespace std;
bool compareNumbers(string a, string b)
{
    if(a.length() != b.length())
        return a.length() < b.length();
    return a < b;
}
int main()
{
    int n;
    cin >> n;
    string arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n, compareNumbers);
    for(int i = 0; i < n; i++)
        cout << arr[i] << endl;
    return 0;
}
