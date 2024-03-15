#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k, n, m; cin >> k >> n >> m;
    vector<int> a(n), b(m);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> ans;
    auto go = [&](vector<int>& vec) {
        bool g = false;
        while (!vec.empty()) {
            if (!vec.back() || k >= vec.back()) {
                if (!vec.back()) k++;
                ans.push_back(vec.back());
                vec.pop_back();
                g = true;
            }
            else break;
        }
        return g;
        };
    while (true) {
        bool f = go(a) || go(b);
        if (!f) break;
    }
    if (ans.size() != n + m) {
        cout << -1 << endl;
        return;
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}