/*
HACKERRANK PROBLEM: Fraudulent Activity Notifications

Problem:
Given an array of daily expenditures and a number d (trailing days),
determine the number of times a notification would be sent for fraudulent activity.

A notification is sent on day i if expenditure[i] >= 2 * median of previous d days.
A subarray of the previous d days is considered, and median is calculated from it.

Constraints:
1 <= n <= 2*10^5
0 <= expenditure[i] <= 200
*/
#include <bits/stdc++.h>
using namespace std;

// get median from counting sort frequency array
double getMedian(const vector<int>& freq, int d) {
    int count = 0;
    if(d % 2 == 1) { // odd
        int mid = d/2 + 1;
        for(int i = 0; i <= 200; i++) {
            count += freq[i];
            if(count >= mid) return i;
        }
    } else { // even
        int first = -1, second = -1;
        int mid1 = d/2, mid2 = d/2 + 1;
        for(int i = 0; i <= 200; i++) {
            count += freq[i];
            if(count >= mid1 && first == -1) first = i;
            if(count >= mid2) { second = i; break; }
        }
        return (first + second)/2.0;
    }
    return 0.0;
}

// main logic function
int activityNotifications(vector<int>& expenditure, int d) {
    vector<int> freq(201, 0);
    int n = expenditure.size();
    int notifications = 0;

    for(int i = 0; i < d; i++) freq[expenditure[i]]++; // initialize freq

    for(int i = d; i < n; i++) {
        double median = getMedian(freq, d);
        if(expenditure[i] >= 2 * median) notifications++;
        freq[expenditure[i]]++;           // add current day
        freq[expenditure[i - d]]--;       // remove trailing day
    }

    return notifications;
}

// simplified main function for HackerRank or local testing
int main() {
    int n, d;
    cin >> n >> d;
    vector<int> expenditure(n);
    for(int i = 0; i < n; i++) cin >> expenditure[i];

    cout << activityNotifications(expenditure, d) << endl;
}
