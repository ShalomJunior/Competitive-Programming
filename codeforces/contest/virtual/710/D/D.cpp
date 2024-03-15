#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> h;
    int M = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        M = max(M, ++h[a]);
    }
    cout << (M <= n / 2 ? n % 2 : n - 2 * (n - M)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}