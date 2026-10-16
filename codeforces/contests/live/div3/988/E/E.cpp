#include <bits/stdc++.h> 
#define int long long
using namespace std;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> a(k + 1, vector<int>(n + 1));
    vector<vector<int>> b(k + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> a[j][i];
            b[j][i] = b[j][i - 1] | a[j][i];
        }
    }
    while (q--) {
        int m;
        cin >> m;
        int L = 1, R = n;
        for (int i = 0; i < m; i++) {
            int r, c;
            char o;
            cin >> r >> o >> c;
            if (o == '<') {
                auto it = lower_bound(b[r].begin(), b[r].end(), c);
                it--;
                int end = it - b[r].begin();
                R = min(R, end);
            }
            else {
                auto it = upper_bound(b[r].begin(), b[r].end(), c);
                int start = it - b[r].begin();
                L = max(L, start);
            }
        }
        cout << (L <= R ? L : -1) << endl;
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
