#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    char c;
    cin >> n >> c;
    map<char, vector<int>> mp;
    for (int i = 0; i < 2 * n; i++) {
        string s; cin >> s;
        mp[s[1]].push_back(s[0] - '0');
    }
    vector<int> rem;
    for (auto& [k, v] : mp) {
        sort(v.begin(), v.end());
        if (k == c)continue;
        if (v.size() % 2)rem.push_back(v[0]);
    }
    if (mp[c].size() < rem.size()) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (auto& [k, v] : mp) {
        if (k == c) continue;
        int m = v.size();
        for (int i = 0; i + 1 < m; i += 2) {
            cout << v[i] << k << " ";
            cout << v[i + 1] << k << endl;
        }
        if (m & 1) {
            cout << v.back() << k << " ";
            cout << mp[c].back() << c << endl;
            mp[c].pop_back();
        }
    }
    for (int i = 0; i < mp[c].size(); i += 2) {
        cout << mp[c][i] << c << " ";
        cout << mp[c][i + 1] << c << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
