#include <bits/stdc++.h>
#define ll long long
using namespace std;

void out(int n) { cout << n << endl; }

void solve() {
    ll a, b, c; cin >> a >> b >> c;
    ll f = a - 1;
    ll s = abs(b - c) + abs(c - 1);

    if (f < s) { out(1); }
    else if (f == s) { out(3); }
    else { out(2); }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}