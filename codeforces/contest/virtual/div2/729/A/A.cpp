#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int o = 0, e = 0;
    for (int i = 0; i < 2 * n; i++) {
        int x; cin >> x;
        x & 1 ? o++ : e++;
    }
    cout << (o == e ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}