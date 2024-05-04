#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, vector<int>> id;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        id[a[i]].push_back(i);
    }
    vector<int> x;
    for (auto& [k, vec] : id) {
        if (vec.size() >= 2)x.push_back(k);
    }
    int zx = x.size();
    if (zx < 2) {
        cout << -1 << endl;
        return;
    }
    vector<int> b(n);
    bool f = false, g = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == x[0]) {
            b[i] = f ? 2 : 1;
            f = true;
        }
        else if (a[i] == x[1]) {
            b[i] = g ? 3 : 1;
            g = true;
        }
        else b[i] = 3;
    }
    for (auto& c : b) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}