#include <bits/stdc++.h>
#define int long long
using namespace std;

uint64_t rng() {
    static mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<uint64_t> distribution(0, numeric_limits<uint64_t>::max());
    return distribution(generator);
}

const int INF = 4e18;
void solve() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        h[i] = rng() % INF;
    }
    int ans = 0;
    map<int, int> dp;
    set<int> used;
    for (int j = 0; j < m; j++) {
        int hash = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j]) {
                hash ^= h[i];
            }
        }
        for (int i = 0; i < n; i++) {
            hash ^= h[i];
            dp[hash]++;
            if (dp[hash] > ans) {
                ans = dp[hash];
                used.clear();
                for (int k = 0; k < n; k++) {
                    if (k == i) {
                        if (a[k][j] == 0) used.insert(k);
                    }
                    else {
                        if (a[k][j]) used.insert(k);
                    }
                }
            }
            hash ^= h[i];
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << (used.count(i) ? "1" : "0");
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
