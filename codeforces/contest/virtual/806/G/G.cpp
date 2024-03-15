#include <bits/stdc++.h>
using namespace std;

const long long INF = 5e18;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<long long> pre(n + 1);
    for (int i = 1; i < n + 1; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }
    long long ans = -INF;
    for (int i = 0; i <= n; i++) {
        long long v = pre[i] - 1LL * i * k;
        for (int j = i; j < min(i + 29, n); j++) {
            v += a[j] / (1 << (j - i + 1));
        }
        ans = max(ans, v);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}