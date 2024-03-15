
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n; cin >> n;
    int mn = INF;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        mn = min(mn, v);
        a[i] = v;
    }
    int ans = 0;
    for (auto& c : a)ans += (c - mn);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}