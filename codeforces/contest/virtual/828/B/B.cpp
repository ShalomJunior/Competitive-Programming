#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector <ll> v(n);

    ll sm = 0;
    ll odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i]; sm += v[i];
        if (v[i] & 1)odd++;
        else even++;
    }

    for (int i = 0; i < q; i++) {
        ll t, plus; cin >> t >> plus;
        if (t & 1) {
            sm += odd * plus;
            if (plus & 1) {
                even += odd; odd = 0;
            }
        }
        else {
            sm += even * plus;
            if (plus & 1) {
                odd += even; even = 0;
            }
        }
        cout << sm << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}