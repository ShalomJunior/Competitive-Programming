#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 43;
const int MOD = 1e9 + 7;
vector<int> LCM(N);
void solve() {
    int n; cin >> n;
    vector<int> a(N);
    for (int i = 1; i < N; i++) {
        a[i] = n / LCM[i];
    }
    int ans = 0;
    for (int i = 1; i < N - 1; i++) {
        int add = (a[i] - a[i + 1]) * (i + 1);
        add %= MOD;
        ans = (ans + add) % MOD;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LCM[0] = 1;
    for (int i = 1; i < N; i++) LCM[i] = lcm(LCM[i - 1], i);
    int t; cin >> t;
    while (t--)solve();
}