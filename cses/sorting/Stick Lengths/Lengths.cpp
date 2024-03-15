#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n; cin >> n;
    vector<ll> v(n);
    for (auto& c : v) cin >> c;

    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(v[i] - v[n / 2]);
    }
    cout << ans << endl;
}