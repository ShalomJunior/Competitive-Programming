#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll luck(ll n) {
    vector<ll> dig;
    while (n > 0) {
        dig.push_back(n % 10);
        n /= 10;
    }
    sort(dig.begin(), dig.end());
    ll ans = dig.back() - dig[0];

    return ans;
}

void solve() {
    ll l, r; cin >> l >> r;
    ll curr = 10, num = l;
    for (int i = l; i <= r; i++) {
        ll nw = luck(i);
        if (nw == 0) {
            cout << i << endl;
            return;
        }
        else if (nw < curr) {
            curr = nw; num = i;
        }
    }
    cout << num << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}