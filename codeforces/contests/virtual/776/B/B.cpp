#include <bits/stdc++.h>
using namespace std;

void solve() {
    int L, R, a; cin >> L >> R >> a;
    int l = L / a, r = R / a;
    if (R % a == a - 1) cout << r + a - 1;
    else cout << (l == r ? r + R % a : r - 1 + a - 1);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}