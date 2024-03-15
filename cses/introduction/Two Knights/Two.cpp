#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool in(ll i, ll j, ll n) {
    return !(i < 0 || i >= n || j < 0 || j >= n);
}

ll all(ll i, ll j, ll n) {
    ll ans = 0;
    if (in(i - 1, j + 2, n))ans++;
    if (in(i + 1, j + 2, n))ans++;
    if (in(i - 1, j - 2, n))ans++;
    if (in(i + 1, j - 2, n))ans++;

    if (in(i - 2, j + 1, n))ans++;
    if (in(i - 2, j - 1, n))ans++;
    if (in(i + 2, j + 1, n))ans++;
    if (in(i + 2, j - 1, n))ans++;

    cout << "n = " << n << " ex = " << ans << endl;
    return ans;
}

void solve(ll n) {
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            ll ex = all(i, j, n);
            if (n * n - 1 - ex > 0)
                ans += n * n - 1 - ex;
        }
    }
    cout << 2 * ans << endl;
}

int main() {
    ll n; cin >> n;
    for (ll i = 1; i <= n; i++) solve(i);
}