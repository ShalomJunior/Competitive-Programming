#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    vector<ll> v(n);
    for (auto& c : v)
        cin >> c;

    ll num = 1;
    ll den = 1;
    for (int i = 0; i < n; i++) {
        num *= v[i];
        den *= (i + 1);
        cout << num / den << " ";
    }

    cout << endl;
}




int main() {
    int t; cin >> t;
    while (t--) solve();
}