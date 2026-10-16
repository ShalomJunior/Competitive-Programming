#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int L = 0;
    int R = min(m, r);
    if (r < m) {
        L = -(m - r);
    }
    cout << L << " " << R << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
