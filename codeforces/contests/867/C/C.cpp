#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n; cin >> n;
    cout << n * (n + 1) + (n + 2) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}