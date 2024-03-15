#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    map<int, int> L, R;
    for (auto& c : a) R[c]++;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int v = a[i];
        R[v]--;
        for (int j = v - 2; j <= v + 2; j++) {
            for (int k = v - 2; k <= v + 2; k++) {
                if (abs(j - k) <= 2) {
                    ans += L[j] * R[k];
                }
            }
        }
        L[v]++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}