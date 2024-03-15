#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n, q; cin >> n >> q;
    vector<ll> cum(n);
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        if (!i)cum[i] = x;
        else cum[i] = cum[i - 1] + x;
    }

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b; --a, --b;
        if (!a)cout << cum[b] << endl;
        else {
            cout << cum[b] - cum[a - 1] << endl;
        }
    }
}