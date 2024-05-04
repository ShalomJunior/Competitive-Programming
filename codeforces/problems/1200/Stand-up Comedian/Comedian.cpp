#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll a1, a2, a3, a4; cin >> a1 >> a2 >> a3 >> a4;

    if (a2 > a3)swap(a2, a3);

    if (!a1) { cout << 1 << endl; return; }

    ll mx = (a1 + a2 + a3 + a4);
    cout << min(mx, 2 * (a1 + a2) + 1) << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}