#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

void solve() {
    ll n; cin >> n;
    ll ans = sqrt((ld)n);
    if (ans * ans != n)ans++;
    cout << ans - 1 << endl;
}

int main() {
    unordered_set<tuple<int, int, int>> db();

    int t; cin >> t;
    while (t--)solve();
}