#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    vector<int> all;
    for (auto& [l, r] : p) {
        cin >> l >> r;
        l--, r--;
        all.push_back(l);
        all.push_back(r);
    }
    sort(p.begin(), p.end());
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    int m = all.size();
    vector<int> res(m);
    vector<int> start(m);
    multiset<int> run;
    for (int i = 0, j = 0; i < m; i++) {
        while (j < n && p[j].first <= all[i]) {
            run.insert(p[j++].second);
            start[i]++;
        }
        res[i] = run.size();
        while (!run.empty() && *run.begin() <= all[i]) run.erase(*run.begin());
    }
    map<int, int> cnt;
    for (int i = 0; i < m; i++) {
        cnt[res[i]]++;
        if (i > 0) {
            int d = all[i] - all[i - 1] - 1;
            cnt[res[i] - start[i]] += d;
        }
    }
    for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}