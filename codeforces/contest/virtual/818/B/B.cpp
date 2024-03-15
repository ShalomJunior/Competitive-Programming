#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n, w, h; cin >> n >> w >> h;
    vector<int> a(n), b(n);
    for (auto& c : a)cin >> c;
    for (auto& c : b)cin >> c;
    int L = -INF, R = INF;
    for (int i = 0; i < n; i++) {
        int x1 = a[i] - (b[i] - h + w);
        int x2 = a[i] - (b[i] + h - w);
        if (x1 > x2)swap(x1, x2);
        L = max(L, x1), R = min(R, x2);
    }
    cout << ((L > R) ? "NO" : "YES") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}