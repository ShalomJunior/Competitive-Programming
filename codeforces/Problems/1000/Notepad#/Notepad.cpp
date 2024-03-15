#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    unordered_map<string, set<int>> h;
    for (int i = 0; i < n - 1; i++) {
        string sb = s.substr(i, 2);
        h[sb].insert(i);
    }

    for (auto& [str, idxs] : h) {
        if (idxs.size() == 1)continue;

        if (*prev(idxs.end()) - *idxs.begin() > 1) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}