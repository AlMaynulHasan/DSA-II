/* After a team finished their training session on Euro football championship, Valeric was commissioned to gather the balls and sort them into baskets. Overall the stadium has n balls and m baskets. The baskets are positioned in a row from left to right and they are numbered with numbers from 1 to m, correspondingly. The balls are numbered with numbers from 1 to n.

Valeric decided to sort the balls in the order of increasing of their numbers by the following scheme. He will put each new ball in the basket with the least number of balls. And if he's got several variants, he chooses the basket which stands closer to the middle. That means that he chooses the basket for which  is minimum, where i is the number of the basket. If in this case Valeric still has multiple variants, he chooses the basket with the minimum number.

For every ball print the number of the basket where it will go according to Valeric's scheme.

Note that the balls are sorted into baskets in the order of increasing numbers, that is, the first ball goes first, then goes the second ball and so on.

Input
The first line contains two space-separated integers n, m (1 ≤ n, m ≤ 105) — the number of balls and baskets, correspondingly.

Output
Print n numbers, one per line. The i-th line must contain the number of the basket for the i-th ball.

Examples
InputCopy
4 3
OutputCopy
2
1
3
2
InputCopy
3 1
OutputCopy
1
1
1
	*/
#include <bits/stdc++.h>
using namespace std;
struct Basket {
    int balls;
    int dist;
    int index;
    bool operator<(const Basket &other) const {
        if (balls != other.balls) return balls > other.balls;
        if (dist != other.dist) return dist > other.dist;
        return index > other.index;
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<Basket> pq;
    double mid = (m + 1) / 2.0;
    for(int i = 1; i <= m; i++) {
        pq.push({0, abs(i - mid), i});
    }
    for(int i = 1; i <= n; i++) {
        Basket b = pq.top();
        pq.pop();
        cout << b.index << endl;
        b.balls++;
        pq.push(b);
    }
    return 0;
}