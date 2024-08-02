#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    set<int> f(s.begin(), s.end());
    for (auto& c : t) {
        if (!f.count(c)) {
            cout << -1 << endl;
            return;
        }
    }
    vector<vector<int>> ids(N);
    for (int i = 0; i < n; i++) {
        ids[s[i] - 'a'].push_back(i);
    }
    int ans = 0;
    int last = -1;
    for (int i = 0; i < m; ) {
        if (last == -1) ans++;
        int j = t[i] - 'a';
        auto it = upper_bound(ids[j].begin(), ids[j].end(), last);
        if (it == ids[j].end()) {
            last = -1;
        }
        else {
            last = *it;
            i++;
        }
    }
    cout << max(ans, 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
