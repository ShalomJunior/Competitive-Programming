#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    map<int, int> b;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b[x]++;
    }
    vector<int> x;
    for (auto& [k, v] : a) x.push_back(v);
    vector<int> y;
    for (auto& [k, v] : b) y.push_back(v);
    while (!x.empty() && !y.empty()) {
        if (y.back() >= x.back()) {
            x.pop_back();
        }
        y.pop_back();
    }
    cout << (x.empty() ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}