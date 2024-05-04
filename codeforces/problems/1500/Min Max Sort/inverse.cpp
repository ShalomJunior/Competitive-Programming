#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll extended_euclidean(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

ll mod_inverse(ll x, ll p) {
    ll a, b, d;
    d = extended_euclidean(x, p, a, b);
    if (d != 1) {
        // x does not have an inverse in M
        return -1;
    }
    else {
        // a is the inverse of x in M
        return (a % p + p) % p;
    }
}


int main() {
    cout << length(7) << endl;
    ll a, b; cin >> a >> b;
    cout << "ans = " << mod_inverse(a, b) << endl;
}