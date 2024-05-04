#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, k, b, s;
    cin >> n >> k >> b >> s;
    int Q = INF / k;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int q = min({ b, s / k, Q });
        b -= q;
        int x = q * k;
        s -= x;
        int d = min(s, k - 1);
        x += d;
        s -= d;
        a.push_back(x);
    }
    if (s || b) {
        cout << -1 << endl;
        return;
    }
    for (auto& c : a) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}