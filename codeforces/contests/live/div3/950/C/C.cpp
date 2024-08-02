#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    int m;
    cin >> m;
    vector<int> d(m);
    for (auto& c : d) cin >> c;
    map<int, vector<int>> should, can;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            should[b[i]].push_back(i);
        else
            can[b[i]].push_back(i);
    }
    bool flag = true;
    for (int i = 0; i < m; i++) {
        if (!should[d[i]].empty()) {
            can[d[i]].push_back(should[d[i]].back());
            should[d[i]].pop_back();
            flag = true;
        }
        else {
            if (can[d[i]].empty()) flag = false;
            else flag = true;
        }
    }
    for (auto& [k, v] : should) {
        if (!v.empty()) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
