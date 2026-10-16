#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (auto& c : h) cin >> c;
    sort(h.begin(), h.end());
    int j = n - 1;
    int r = 0;
    int ans = 0;
    for (int i = h[n - 1]; i > h[0];) {
        while (h[j - 1] == h[j]) j--;
        int m = n - j;
        if (r < m) {
            r = k;
            ans++;
        }
        else {
            r -= m;
            h[j] = i - 1;
            i--;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
