#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++) {
        dq.push_back({ i, a[i] });
    }
    vector<vector<int>> cnt(n);
    int round = 0;
    while (true) {
        auto f = dq.front();
        dq.pop_front();
        auto s = dq.front();
        dq.pop_front();
        if (f.second < s.second) swap(f, s);
        if (f.second == n) break;
        cnt[f.first].push_back(++round);
        dq.push_front(f);
        dq.push_back(s);
    }
    while (q--) {
        int i, k;
        cin >> i >> k;
        --i;
        if (a[i] == n) {
            cout << max(k - round, 0) << endl;
        }
        else {
            if (cnt[i].empty()) {
                cout << 0 << endl;
                continue;
            }
            auto it = upper_bound(cnt[i].begin(), cnt[i].end(), k);
            if (it == cnt[i].begin()) {
                cout << 0 << endl;
                continue;
            }
            cout << it - cnt[i].begin() << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}