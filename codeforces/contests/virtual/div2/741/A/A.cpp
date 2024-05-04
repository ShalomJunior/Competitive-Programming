#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r; cin >> l >> r;
    int a = r, b = max(r / 2 + 1, l);
    cout << a % b << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}