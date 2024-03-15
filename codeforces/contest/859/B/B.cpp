#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int even = 0, odd = 0;

    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        if (v & 1) odd += v;
        else even += v;
    }

    cout << ((even > odd) ? "YES" : "NO") << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}