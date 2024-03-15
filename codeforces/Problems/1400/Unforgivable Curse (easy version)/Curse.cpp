#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;

    bool zero = true;
    unordered_map<char, int> db;
    for (int i = 0; i < n; i++) {
        if (i + k >= n && i - k < 0) {
            if (s[i] != t[i]) {
                cout << "NO" << endl;
                return;
            }
        }
        else {
            db[s[i]]++;
            db[t[i]]--;
        }
    }
    for (auto& [k, v] : db) {
        if (v) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}