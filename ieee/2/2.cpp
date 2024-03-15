#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, h0, a, c, q;
    cin >> n >> h0 >> a >> c >> q;
    vector<int> vals(n); vals[0] = h0;
    for (int i = 1; i < n; i++) {
        long long x = 1LL * a * vals[i - 1] + c;
        x %= q;
        vals[i] = x;
    }
    long long ans = 0;
    for (int i = 1, cnt = 0; i < n; i++) {
        if (vals[i] >= vals[i - 1]) {
            ans += 1LL * cnt * (cnt + 1) / 2;
            ans++;
            cnt = 0;
        }
        else cnt++;
        if (i == n - 1) {
            ans += 1LL * cnt * (cnt + 1) / 2;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}