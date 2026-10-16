#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(int t) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int ans = 0;
    int ended = 0;
    for (int i = 0; i < n; i++) {
        if (ended <= a[i]) {
            ended += a[i];
            ans++;
        }
    }
    cout << "Case #" << t << ": " << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}