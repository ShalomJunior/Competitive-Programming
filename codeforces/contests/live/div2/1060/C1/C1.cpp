#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<vector<int>> divs(N + 1);
vector<int> g(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> h;
    for (auto& c : a) {
        cin >> c;
        if (divs[c].empty()) {
            divs[c] = g(c);
        }
        for (auto& x : divs[c]) h[x]++;
    }
    vector<int> b(n);
    for (auto& c : b) cin >> c;
    for (auto& [k, v] : h) {
        if (k != 1 && v > 1) {
            cout << 0 << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        int u = a[i] + 1;
        if (divs[u].empty()) {
            divs[u] = g(u);
        }
        for (auto& x : divs[u]) {
            if (x != 1 && h.find(x) != h.end()) {
                cout << 1 << endl;
                return;
            }
        }
    }
    cout << 2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
