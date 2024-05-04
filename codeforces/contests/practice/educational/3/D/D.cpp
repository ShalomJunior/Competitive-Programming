#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    vector<pair<int, int>> g(m);
    for (auto& [t, c] : g) cin >> t >> c;
    vector<pair<int, int>> all;
    auto check = [&](int day) {
        all.clear();
        int d = *min_element(a.begin(), a.begin() + day);
        int p = *min_element(b.begin(), b.begin() + day);
        for (int i = 0; i < m; i++) {
            auto& [t, c] = g[i];
            int val = t == 1 ? c * d : c * p;
            all.push_back({ val, i + 1 });
        }
        sort(all.begin(), all.end());
        int need = 0;
        for (int i = 0; i < k; i++) need += all[i].first;
        return need <= s;
        };
    int L = 1, R = n;
    while (L < R) {
        int mid = (L + R) / 2;
        check(mid) ? R = mid : L = mid + 1;
    }
    if (!check(R)) {
        cout << -1 << endl;
        return;
    }
    cout << R << endl;
    int x = min_element(a.begin(), a.begin() + L) - a.begin() + 1;
    int y = min_element(b.begin(), b.begin() + L) - b.begin() + 1;
    for (int i = 0; i < k; i++) {
        auto [_, id] = all[i];
        cout << id << " " << (g[id - 1].first == 1 ? x : y) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
