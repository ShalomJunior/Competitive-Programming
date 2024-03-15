#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    set<int> sec;
    unordered_map<int, int> mp;
    int ones = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i].size() == 1) {
            mp[v[i][0]]++;
            sec.insert(v[i][0]);
        }
    }
    cout << sec.size() << " " << mp.begin()->second << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}