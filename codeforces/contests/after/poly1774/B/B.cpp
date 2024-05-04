#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>());
    unordered_map<int, int> data;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        a[i].resize(k);
        for (auto& c : a[i]) {
            cin >> c;
            data[c]++;
        }
    }
    for (int i = 0; i < n; i++) {
        bool good = true;
        for (auto& c : a[i]) {
            good &= data[c] >= 2;
        }
        if (good) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}