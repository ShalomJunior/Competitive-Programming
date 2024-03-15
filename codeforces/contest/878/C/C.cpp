#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, q; cin >> n >> k >> q;
    long long ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        if (temp <= q) cnt++;
        if (temp > q || i == n - 1) {
            if (cnt >= k) {
                long long sup = cnt - k + 1;
                ans += sup * (sup + 1) / 2;
            }
            cnt = 0;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}