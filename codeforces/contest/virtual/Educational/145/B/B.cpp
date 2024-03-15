#include <bits/stdc++.h>
#define ll long long 

using namespace std;

void solve() {
    ll n; cin >> n;
    if (n < 5) {
        if (n == 1) cout << 0 << endl;
        else cout << 1 << endl;
        return;
    }

    ll ans = sqrt(n);
    ll i = (ans & 1) ? ans : ans + 1;
    for (;; i += 2) {
        if (i * i >= n)break;
    }
    cout << i - 1 << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}