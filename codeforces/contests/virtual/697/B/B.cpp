#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int q = n / 2020, r = n % 2020;
    cout << (r <= q ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}