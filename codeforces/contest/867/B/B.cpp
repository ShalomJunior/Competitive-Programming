#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n; cin >> n;
    if (n == 2) {
        ll a, b; cin >> a >> b;
        cout << a * b << endl;
        return;
    }

    vector<ll> pos, neg;
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        if (a >= 0)pos.push_back(a);
        else neg.push_back(a);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    int n1 = (int)pos.size();
    int n2 = (int)neg.size();

    ll mx1 = 0;
    ll mx2 = 0;

    if (n1 > 1)mx1 = pos[n1 - 1] * pos[n1 - 2];
    if (n2 > 1)mx2 = neg[0] * neg[1];

    cout << max(mx1, mx2) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}