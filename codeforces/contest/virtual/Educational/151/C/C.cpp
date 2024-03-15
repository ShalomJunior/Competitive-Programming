#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

const int D = 10;
int m; string s, l, r;
vector<vector<int>> idx(D);

pair<bool, int> Dfs(int id, int last, int lim) {
    if (!lim) return make_pair(true, last);
    pair<bool, int> ans = { true, last };
    for (int i = l[id] - '0'; i <= r[id] - '0'; i++) {
        auto it = upper_bound(idx[i].begin(), idx[i].end(), last);
        if (it == idx[i].end()) {
            return make_pair(false, -1);
        }
        auto p = Dfs(id + 1, *it, lim - 1);
        if (!p.F) return make_pair(false, -1);
        ans.S = max(ans.S, p.S);
    }
    return ans;
};

void solve() {
    idx = vector<vector<int> >(D);
    cin >> s >> m >> l >> r;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        idx[s[i] - '0'].push_back(i);
    }
    int id = 0, last = -1;
    while (m) {
        int lim = min(m, 4);
        auto ans = Dfs(id, last, lim);
        if (!ans.F) {
            cout << "YES" << endl;
            return;
        }
        m -= lim;
        last = ans.S;
        id += lim;
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}