#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    int g = gcd(a, b);
    a /= g, b /= g;
    if (a == 1) cout << 1LL * g * b * b;
    else cout << 1LL * a * b * g;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
