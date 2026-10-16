#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> pos;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        pos[b[i]].push_back(i);
    }
    int val = 1;
    vector<int> ans(n);
    for (auto& [k, v] : pos) {
        int m = v.size();
        if (m % k) {
            cout << -1 << endl;
            return;
        }
        while (!v.empty()) {
            for (int i = 0; i < k; i++) {
                ans[v.back()] = val;
                v.pop_back();
            }
            val++;
        }
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
