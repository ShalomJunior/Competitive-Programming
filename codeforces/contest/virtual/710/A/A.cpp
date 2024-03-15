#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m, x;
    cin >> n >> m >> x;
    int abs = x / n + (x % n ? 1 : 0), ord = (x % n ? x % n : n);
    cout << ((ord - 1) * m + abs) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}