#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    set<int> m;
    int O = 0, E = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        m.insert(a);
        (a & 1) ? O++ : E++;
    }

    if (O % 2 == 0 && E % 2 == 0) { cout << "YES" << endl; return; }

    for (auto it = m.begin(); it != m.end(); ++it) {
        if (m.count(*it + 1)) { cout << "YES" << endl; return; }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}