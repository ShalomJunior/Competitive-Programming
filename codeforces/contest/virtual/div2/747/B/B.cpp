#include <bits/stdc++.h>
using namespace std;

const int N = 30;
const int MOD = 1e9 + 7;
void solve() {
    int n, k; cin >> n >> k;
    long long ans = 0, m = 1;
    for (int i = 0; i <= N; i++) {
        int mask = 1 << i;
        if (k & mask) {
            ans = (ans + m) % MOD;
        }
        m = (m * n) % MOD;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}