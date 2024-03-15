#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> v;

ll sum(int a, int b) {
    ll ans = 0;
    while (a <= b) {
        if (a & 1)ans += v[a++];
        if (b % 2 == 0) ans += v[b--];
        a /= 2; b /= 2;
    }
    return ans;
}

void up(int i, ll val) {
    ll delta = val - v[i];
    while (i > 0) {
        v[i] += delta;
        i /= 2;
    }
}

int sz(int n) {
    int ex = log2(n);
    if (pow(2, ex) == n) return n;
    return pow(2, ex + 1);
}

int main() {
    int n, q; cin >> n >> q;
    int s = sz(n);
    v.resize(2 * s);
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        v[s + i] = x;
    }
    //Build segment tree
    for (int i = s - 1; i > 0; i--) {
        v[i] = v[2 * i] + v[2 * i + 1];
    }

    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        ll x, y; cin >> x >> y;
        if (t & 1) {
            --x;
            up(s + x, y);
        }
        else {
            --x; --y;
            ll ans = sum(s + x, s + y);
            cout << ans << endl;
        }
    }
}