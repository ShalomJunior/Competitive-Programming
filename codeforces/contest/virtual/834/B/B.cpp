#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m, s; cin >> m >> s;
    unordered_set<int> v;
    int mx = INT_MIN;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        mx = max(mx, x);
        v.insert(x);
    }

    int add = 0;
    for (int i = 1; i < mx; i++)
        if (!v.count(i)) add += i;

    for (int i = mx + 1; add < s;i++)
        add += i;

    cout << ((add == s) ? "YES" : "NO") << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}