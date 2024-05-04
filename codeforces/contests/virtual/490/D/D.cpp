#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> r(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r[a[i] % m].push_back(i);
    }
    int d = n / m;
    set<int> less;
    for (int i = 0; i < m; i++) {
        if (r[i].size() < d) less.insert(i);
    }
    int mn = 0;
    for (int i = 0; i < m; i++) {
        int cnt = r[i].size();
        if (cnt > d) {
            int sup = cnt - d;
            while (sup) {
                auto it = less.lower_bound(i);
                int to = (it == less.end() ? *less.begin() : *it);
                int need = d - r[to].size();
                int can = min(sup, need);
                int per = (to < i ? to + m - i : to - i);
                for (int k = 0; k < can; k++) {
                    int j = r[i].back();
                    a[j] += per; mn += per;
                    r[to].push_back(j);
                    r[i].pop_back();
                }
                sup -= can;
                if (can == need) less.erase(to);
            }
        }
    }
    cout << mn << endl;
    for (auto& c : a)cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}