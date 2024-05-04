#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int g = a[1] - a[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i] - a[i - 1]);
    }
    cout << (g ? g : -1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}