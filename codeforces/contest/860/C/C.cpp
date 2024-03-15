#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    vector<ll> all(n);
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        all[i] = a * b;
    }

}

int main() {
    int t; cin >> t;
    while (t--)solve();
}