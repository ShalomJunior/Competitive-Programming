#include <bits/stdc++.h>
#define int long long
using namespace std;

void merge(vector<pair<int, int>>& x) {
    int n = x.size();
    if (n == 0) return;
    sort(x.begin(), x.end());
    vector<pair<int, int>> temp;
    int l = x[0].first;
    int r = x[0].second;
    for (int i = 1; i < n; i++) {
        if (x[i].first > r) {
            temp.push_back({ l, r });
            l = x[i].first;
            r = x[i].second;
        }
        else {
            r = max(r, x[i].second);
        }
    }
    temp.push_back({ l, r });
    x = temp;
}
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> p;
    p.push_back({ m - 1, m - 1 });
    while (q--) {
        int j;
        cin >> j;
        j--;
        int z = p.size();
        vector<pair<int, int>> np;
        for (auto& [l, r] : p) {
            if (r < j) np.push_back({ l, r + 1 });
            else {
                if (l <= j) {
                    np.push_back({ 0, 0 });
                    np.push_back({ n - 1, n - 1 });
                }
                if (l < j)
                    np.push_back({ l, j });
            }
        }
        for (int i = 0; i < z; i++) {
            auto [l, r] = p[i];

            if (l > j) np.push_back({ l - 1, r });
            else {
                if (r >= j) {
                    np.push_back({ 0, 0 });
                    np.push_back({ n - 1, n - 1 });
                }
                if (r > j)
                    np.push_back({ j, r });

            }
        }
        p = np;
        merge(p);
        int ans = 0;
        for (auto& [l, r] : p) {
            ans += r - l + 1;
        }
        cout << ans << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
