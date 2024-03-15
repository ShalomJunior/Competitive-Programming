#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    set<int> id;
    for (int i = 0; i < m; i++) {
        int p; cin >> p;
        --p;
        id.insert(p);
    }
    vector<int> ans;
    for (int i = 0; i < n; ) {
        vector<int> t = { a[i] };
        int j = i;
        while (id.count(j)) {
            t.push_back(a[++j]);
        }
        i = (j == i ? i + 1 : j + 1);
        sort(t.begin(), t.end());
        for (auto& c : t) ans.push_back(c);
        t = {};
    }
    cout << (is_sorted(ans.begin(), ans.end()) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}