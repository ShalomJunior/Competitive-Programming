#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n; cin >> n;
    vector<ll> v(n);
    for (auto& c : v) cin >> c;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) {
            ans += v[i - 1] - v[i];
            v[i] = v[i - 1];
        }
    }
    cout << ans << endl;
}