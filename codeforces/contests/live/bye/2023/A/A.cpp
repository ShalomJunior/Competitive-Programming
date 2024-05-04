#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    long long x = 1;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        x *= c;
    }
    if (2023 % x) cout << "NO";
    else {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++) cout << 1 << " ";
        cout << 2023 / x;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
