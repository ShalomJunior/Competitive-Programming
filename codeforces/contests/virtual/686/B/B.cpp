#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, vector<int>> h;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        h[x].push_back(i);
    }
    for (auto& [k, v] : h) {
        if (v.size() == 1) {
            cout << v[0] + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}