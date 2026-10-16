#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(N, vector<int>(n));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int M = 2 * n;
    int ans = 0;
    int lx = 0;
    int rx = M + 1;
    vector<pair<int, int>> all;
    function<void(int, int, int, int)> go = [&](int i, int j, int L, int R) {
        if (i == N - 1 && j == n - 1) {
            if (L <= R) {
                all.push_back({ L, R });
            }
            return;
        }
        L = min(L, a[i][j]);
        R = max(R, a[i][j]);
        if (i + 1 < N)
            go(i + 1, j, L, R);
        if (j + 1 < n)
            go(i, j + 1, L, R);
        };
    go(0, 0, M, 0);
    sort(all.begin(), all.end());
    set<int> l;
    for (auto& [x, y] : all) l.insert(x);
    set<int> r;
    for (int i = 0, j = 0; i < M; i++) {
        int r = 0;
        int cnt =
            while (j < all.size() && all[j].first == 1) {
                l.in
                    in.insert(all[j].second);
                j++;
            }
        if (!l.empty()) {

        }
        l.erase(i);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}