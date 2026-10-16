#include <bits/stdc++.h>
using namespace std;

void solve() {
    double r, s, x;
    cin >> r >> s >> x;
    double ans = s * s * x / (r * r);
    long long p = ceil(ans);
    while (p % 10) p++;
    cout << p << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}