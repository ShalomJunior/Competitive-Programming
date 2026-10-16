#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 31;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(N);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < N; j++) {
            int mask = 1 << j;
            if (a[i] & mask) {
                cnt[j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int curr = 0;
        for (int j = 0; j < N; j++) {
            int mask = 1 << j;
            if (a[i] & mask) {
                curr += (n - cnt[j]) * mask;
            }
            else {
                curr += cnt[j] * mask;
            }
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
