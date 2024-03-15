#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
int main() {
    ll n; cin >> n;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= 2;
        ans %= MOD;
    }
    cout << ans << endl;
}