#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6;
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> b(m);
    for (auto& c : b) cin >> c;
    int s1 = accumulate(a.begin(), a.end(), 0LL);
    int s2 = accumulate(b.begin(), b.end(), 0LL);
    vector<int> f(2 * N);
    for (int i = 0; i < n; i++) {
        if (s1 - a[i] + N < 2 * N)
            f[s1 - a[i] + N] = true;
    }
    vector<int> g(2 * N);
    for (int j = 0; j < m; j++) {
        if (s2 - b[j] + N < 2 * N)
            g[s2 - b[j] + N] = true;
    }
    while (q--) {
        int x;
        cin >> x;
        bool flag = false;
        for (int i = 1; i * i <= abs(x); i++) {
            if (x % i == 0) {
                int d1 = i;
                int d2 = x / i;
                for (int l : {d1, d2, -d1, -d2}) {
                    for (int r : {d1, d2, -d1, -d2}) {
                        if (l * r == x) {
                            if (f[l + N] && g[r + N]) flag = true;
                        }
                    }
                }
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}