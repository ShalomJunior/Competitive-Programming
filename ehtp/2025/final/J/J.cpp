#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && abs(a[i] - a[j]) <= d) ans++;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}