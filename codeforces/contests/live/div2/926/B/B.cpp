#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if ((2 * n - 2) * 2 >= k) cout << (k + 1) / 2;
    else if (k == 4 * n - 2) cout << 2 * n;
    else cout << 2 * n - 1;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
