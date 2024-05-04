#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, x, t;
    cin >> n >> x >> t;
    long long j = n - 1 - t / x;
    if (j < 0) {
        cout << n * (n - 1) / 2 << endl;
    }
    else {
        j++;
        if ((j * x + t) / x + 1 > n) j--;
        if ((j * x + t) / x + 1 <= n) j++;
        long long ans = j * (t / x) + (n - j) * n;
        ans -= (n - j) * (j + 1 + n) / 2;
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}