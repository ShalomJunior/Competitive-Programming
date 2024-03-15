#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> b(n - 1);
    unordered_map<int, vector<int>>mp;
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
        mp[i].push_back(b[i]);
        mp[i + 1].push_back(b[i]);
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        auto pos = mp[i];
        if (pos.size() == 1)a[i] = pos[0];
        else {
            if (pos[0] <= b[i])a[i] = pos[0];
            else a[i] = pos[1];
        }
    }
    for (auto& c : a)cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}