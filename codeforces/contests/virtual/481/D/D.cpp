#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e15;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    if (n < 3) { cout << 0 << endl; return; }
    int m = INF, M = 0;
    for (int i = 0; i < n - 1; i++) {
        int d = abs(a[i] - a[i + 1]);
        m = min(m, d);
        M = max(M, d);
    }
    if (M - m > 4) { cout << -1 << endl; return; }
    int ans = INF;
    for (int r = M - 4; r <= m + 4; r++) {
        for (int a0 : {a[0] - 1, a[0], a[0] + 1}) {
            for (int t : {-1, 1}) {
                bool flag = true;
                int diff = 0;
                for (int i = 0; i < n; i++) {
                    int u = a0 + i * r * t;
                    if (abs(a[i] - u) > 1) {
                        flag = false;
                        break;
                    }
                    if (a[i] != u) diff++;
                }
                if (flag) ans = min(ans, diff);
            }
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}