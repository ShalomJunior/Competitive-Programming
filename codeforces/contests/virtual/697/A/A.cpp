#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n; cin >> n;
    while (n > 1 && n % 2 == 0) n /= 2;
    cout << (n > 1 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}