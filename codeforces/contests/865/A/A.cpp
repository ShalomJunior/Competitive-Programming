#include <bits/stdc++.h>

using namespace std;

const int M = 1e9;

void solve() {
    int a, b; cin >> a >> b;
    cout << 2 << endl;
    cout << 1 << " " << ((b == M) ? b - 1 : b + 1) << endl;
    cout << a << " " << b << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}