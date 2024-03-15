#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    int neg = 0, sum = 0, mn = 2e9;
    vector<int> a(n);
    for (auto& c : a) {
        cin >> c;
        if (c < 0) { neg++; c *= -1; }
        sum += c;
        mn = min(mn, c);
    }
    if (neg & 1) sum -= 2 * mn;
    cout << sum << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}