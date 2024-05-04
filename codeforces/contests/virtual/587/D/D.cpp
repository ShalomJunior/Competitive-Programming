#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    vector<int> d;
    for (int i = 0; i < n - 1; i++) {
        d.push_back(a[n - 1] - a[i]);
    }
    int g = d[0];
    for (auto& c : d) g = gcd(g, c);
    int p = 0;
    for (int i = 0; i < n; i++) {
        p += (a[n - 1] - a[i]) / g;
    }
    cout << p << " " << g << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}