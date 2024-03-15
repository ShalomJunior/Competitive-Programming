#include <bits/stdc++.h>
using namespace std;

bool go(int n, int m) {
    if (n == m) return true;
    if (n % 3 || n < m) return false;
    return (go(n / 3, m) | go(2 * n / 3, m));
}

void solve() {
    int n, m; cin >> n >> m;
    cout << ((go(n, m) ? "YES" : "NO")) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}