#include <bits/stdc++.h>
using namespace std;

void solve() {
    int xa, ya, xb, yb, xf, yf;
    cin >> xa >> ya >> xb >> yb >> xf >> yf;
    int moves = abs(xa - xb) + abs(ya - yb);
    if ((xa == xb && xa == xf && min(ya, yb) < yf && yf < max(ya, yb)) ||
        (ya == yb && ya == yf && min(xa, xb) < xf && xf < max(xa, xb)))
        moves += 2;
    cout << moves << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}