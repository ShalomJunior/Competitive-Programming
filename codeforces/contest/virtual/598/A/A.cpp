#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, n, s; cin >> a >> b >> n >> s;
    if (s % n > b) {
        cout << "NO" << endl;
        return;
    }
    b -= s % n;
    s -= s % n;
    long long mx = 1LL * a * n + b;
    cout << (mx >= 1LL * s ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}