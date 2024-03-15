#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, k; cin >> n >> k;
    ll g = gcd(2, k);
    cout << ((n % g) ? "NO" : "YES") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}