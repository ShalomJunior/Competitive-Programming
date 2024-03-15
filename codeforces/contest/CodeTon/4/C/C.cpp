#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = LONG_LONG_MAX;

void solve() {
    ll n, c, d; cin >> n >> c >> d;

    ll del_cost = 0;
    set<ll> is;
    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        if (is.count(a)) del_cost += c;
        else is.insert(a);
    }

    ll mn = INF, rem = is.size();
    ll cum = del_cost, curr = 1;
    for (auto it = is.begin(); it != is.end(); it++) {
        rem--;
        if (*it != curr) {
            mn = min(mn, cum + d + c * (rem + 1));
            cum += (*it - curr) * d;
        }
        mn = min(mn, cum + c * rem);
        curr = *it + 1;
    }
    cout << mn << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}