#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 < y1) {
        cout << (x2 > y2 ? "NO" : "YES");
    }
    else {
        cout << (x2 < y2 ? "NO" : "YES");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}